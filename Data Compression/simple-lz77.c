/* simple-lz77.c -- Simple LZ77 (Ziv-Lempel) encoding [compression] with
** fixed offset/legth sizes [fixed size window of 4096 {2**12} bytes,
** match lengths of 15 {2**4-1} bytes] and alternating pointers into the
** window dictionary and new symbols [characters].
** The implementation is not optimized for speed [but for simplicity of
** code and data structures].
**
** Copyright (C) 1992,2004 Eric Laroche.  All rights reserved.
**
** @author Eric Laroche <laroche@lrdev.com>, www.lrdev.com
** @version @(#)$Id: simple-lz77.c,v 1.1 2004/05/06 13:27:28 laroche Exp $
**
** Patents may apply to algorithms implemented by this code;
** you need to ensure that your use of such algorithms is legal.
**
** This program is free software;
** you can redistribute it and/or modify it.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**
*/


/* [implemented interface] */
#include "simple-lz77.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>


/** OFFSETBITS+LENGTHBITS.
* POINTERBITS%8 must be 0 to have the encoding output byte-aligned.
*/
#define POINTERBITS 16

/** Number of bits used in encoding offsets into the dictionary window.
* The window size will be 1<<OFFSETBITS.
* Since OFFSETBITS+LENGTHBITS==POINTERBITS [to have byte-aligned bits] and
* LENGTHBITS<=OFFSETBITS [larger strings than window size can't be found
* {if lookahead-self-referencing matches are not considered}] and
* LENGTHBITS>=2 [very short matches don't compress], OFFSETBITS ranges
* from 8 to 14.
*/
#define OFFSETBITS 12

/** Number of bits used to encode lengths of string matches.
* OFFSETBITS+LENGTHBITS are a multiple of 8 to have byte-aligned bits.
*/
#define LENGTHBITS (POINTERBITS - OFFSETBITS)  /* 4 */

#define WINDOWSIZE (1 << OFFSETBITS)  /* 4096 */
#define LOOKAHEADSIZE ((1 << LENGTHBITS) - 1)  /* 15 */
#define POINTERBYTES (POINTERBITS / 8)  /* 2 */


/* typedef struct lz77_st lz77; */

/** A simple Ziv-Lempel 77 dictionary.
*/
struct lz77_st
{
	/** Dictionary window.
	*/
	char window[WINDOWSIZE];
};


/* [local functions] */
static void decodeByDictionary(lz77*, char const*, int, int*, char*, int, int*);
static void encodeByDictionary(lz77*, char const*, int, int*, char*, int, int*);
static int fillBuffer(char*, int, FILE*);
static void findLargest(char const*, int, char const*, int, int*, int*);
static int gcd(int, int);
static int matchLength(char const*, int, char const*, int);
static int maxDictionaryDecodingIn(void);
static int maxDictionaryDecodingOut(void);
static int maxDictionaryEncodingIn(void);
static int maxDictionaryEncodingOut(void);
static void* memrot(void*, int, int);
static int putN(char const*, int, FILE*);
static void updateDictionary(lz77*, char const*, int);


/** Get a lz77 encoder.
* Initiates encoder's state (its dictionary).
* Returns NULL if memory allocation failed.
*/
lz77* lz77_new(void)
{
	lz77* p;

	p = (lz77*)malloc(sizeof(*p));
	if (p == NULL) {
		return NULL;
	}

	assert(WINDOWSIZE > 0);

	/* initialize {en/de}coder/dictionary state */
	memset(p->window, 0, WINDOWSIZE);  /* zeroed dictionary */

	return p;
}


/** Dispose a lz77 encoder.
*/
void lz77_delete(lz77* p)
{
	if (p == NULL) {  /* NULL is ok as argument */
		return;
	}

	free(p);
}


/** Encode a file stream with a lz77 encoder.
* Does not initiate encoder's state (its dictionary).
*/
void lz77_encode(lz77* p, FILE* in, FILE* out)
{
	int bufferSize, bufferLength, consumed, produced, n;
	char* lookAheadBuffer;
	char outBuffer[2];

	/* have one spare byte besides the look-ahead, for the symbol */
	bufferSize = maxDictionaryEncodingIn() + 1;  /* 15+1 */

	lookAheadBuffer = (char*)malloc(bufferSize);
	if (lookAheadBuffer == NULL) {
		return;
	}

	assert(sizeof(outBuffer) >= maxDictionaryEncodingOut());
	assert(sizeof(outBuffer) == POINTERBYTES);

	bufferLength = 0;

	/* encode */
	for (;;) {

		assert(bufferSize - bufferLength >= 0);

		/* Try to fill the look-ahead buffer.
		* Note: this will check for end-of-input-file-stream more than once.
		*/
		bufferLength += fillBuffer(
			&lookAheadBuffer[bufferLength],
			bufferSize - bufferLength,
			in);

		assert(bufferLength >= 0);
		assert(bufferLength <= bufferSize);

		/* check if all input is done */
		if (bufferLength == 0) {  /* fillBuffer above only caught EOF */
			break;
		}

		/* encode and output pointers */

		consumed = 0;
		produced = 0;
		encodeByDictionary(
			p,
			lookAheadBuffer,
			bufferLength - 1,  /* spare one for the new symbol */
			&consumed,
			outBuffer,
			sizeof(outBuffer),
			&produced);

		assert(consumed >= 0);
		assert(consumed < bufferLength);
		assert(produced == POINTERBYTES);
		assert(POINTERBYTES == 2);

		n = putN(outBuffer, 2, out);
		if (n < 2) {  /* output error */
			break;
		}

		/* update dictionary */
		updateDictionary(p, lookAheadBuffer, consumed);

		assert(bufferLength - consumed >= 0);

		memmove(lookAheadBuffer, &lookAheadBuffer[consumed], bufferLength - consumed);
		bufferLength -= consumed;

		/* output new-symbol */

		assert(bufferLength >= 1);

		n = putN(lookAheadBuffer, 1, out);
		if (n < 1) {  /* output error */
			break;
		}

		/* update dictionary */
		updateDictionary(p, lookAheadBuffer, 1);

		memmove(lookAheadBuffer, &lookAheadBuffer[1], bufferLength - 1);
		bufferLength--;
	}

	free(lookAheadBuffer);
}


/** Try to fill a buffer.
*/
static int fillBuffer(char* buffer, int size, FILE* in)
{
	int i;
	int c;

	assert(buffer != NULL);
	assert(size >= 0);
	assert(in != NULL);

	i = 0;
	while (i < size) {

		c = getc(in);
		if (c == EOF) {
			break;
		}

		buffer[i++] = (char)c;
	}

	return i;
}


/** Try to write a buffer.
*/
static int putN(char const* buffer, int size, FILE* out)
{
	int i;
	int s;

	assert(buffer != NULL);
	assert(size >= 0);
	assert(out != NULL);

	i = 0;
	while (i < size) {

		s = putc(buffer[i], out);
		if (s == EOF) {  /* output error */
			break;
		}

		i++;
	}

	return i;
}


/** Decode a file stream with a lz77 decoder.
* Does not initiate decoder's state (its dictionary).
*/
void lz77_decode(lz77* p, FILE* in, FILE* out)
{
	int bufferSize, n, consumed, produced;
	char* decodeBuffer;
	char inBuffer[2];
	char cc;

	bufferSize = maxDictionaryDecodingOut();  /* 15 */

	decodeBuffer = (char*)malloc(bufferSize);
	if (decodeBuffer == NULL) {
		return;
	}

	assert(sizeof(inBuffer) >= maxDictionaryDecodingIn());
	assert(sizeof(inBuffer) == POINTERBYTES);

	/* decode */
	for (;;) {

		/* fill in-buffer */
		n = fillBuffer(inBuffer, 2, in);
		if (n == 0) {  /* done */
			break;
		}

		if (n < 2) {  /* done at an unexpected position -- partial pointer */
			break;
		}

		/* decode and output */

		consumed = 0;
		produced = 0;
		decodeByDictionary(
			p,
			inBuffer,
			POINTERBYTES,
			&consumed,
			decodeBuffer,
			bufferSize,
			&produced);

		assert(consumed == POINTERBYTES);
		assert(POINTERBYTES == 2);
		assert(produced >= 0);
		assert(produced <= bufferSize);

		n = putN(decodeBuffer, produced, out);
		if (n < produced) {  /* output error */
			break;
		}

		/* update dictionary */
		updateDictionary(p, decodeBuffer, produced);

		/* output new-symbol */

		n = fillBuffer(&cc, 1, in);
		if (n == 0) {  /* done at an unexpected position -- missing last new symbol */
			break;
		}

		n = putN(&cc, 1, out);
		if (n == 0) {  /* output error */
			break;
		}

		/* update dictionary */
		updateDictionary(p, &cc, 1);
	}

	free(decodeBuffer);
}


/** Maximal input size that can be encoded by dictionary, in bytes, not
* depending on [current] dictionary state.
*/
static int maxDictionaryEncodingIn(void)
{
	/* Note: we do not consider current dictionary state, e.g. adjust
	* for current dictionary length [possibly smaller than size], etc.
	*/

	assert(LOOKAHEADSIZE > 0);

	/* 15 bytes (2**4-1, where 4 is the number of bits in length encoding) */
	return LOOKAHEADSIZE;
}


/** Maximal output size in encoding by-dictionary, in bytes, not
* depending on [current] dictionary state.
*/
static int maxDictionaryEncodingOut(void)
{
	assert(POINTERBYTES > 0);

	/* 12 bits dictionary offset encoding, 4 bits length encoding */
	return POINTERBYTES;  /* 2 */
}


/** Encode by-dictionary.
* Note: LZ77 won't encode anything by-dictionary if no match is found
* [in which case inUsed will be 0 and outUsed 2]; this requires
* additional encoding steps, e.g. sending plain symbols [either
* alternating with dictionary encoding or as an alternative].
* Note: inSize=0 is explicitly allowed, to allow zero/non-match encoding
* possibly needed by encoder to spare a last byte as new symbol output.
*/
static void encodeByDictionary(
	lz77* p,
	char const* in,  /* input */
	int inSize,  /* input size, in bytes */
	int* inUsed,  /* returns the number of input bytes consumed after coding */
	char* out,  /* output buffer */
	int outSize,  /* output buffer size, bytes */
	int* outUsed  /* returns the number of output bytes generated by coding */
)
{
	int offset, length;

	assert(inUsed != NULL);
	assert(outUsed != NULL);

	*inUsed = 0;
	*outUsed = 0;

	assert(LOOKAHEADSIZE > 0);

	/* can't encode more than LOOKAHEADSIZE */
	if (inSize > LOOKAHEADSIZE) {
		inSize = LOOKAHEADSIZE;
	}

	/* [already check here that we'll be able to code this length later] */
	assert(inSize < (1 << LENGTHBITS));

	assert(POINTERBYTES > 0);
	assert(outSize >= POINTERBYTES);

	/* [sanity check] */
	if (outSize < POINTERBYTES) {
		return;
	}

	assert(p != NULL);

	/* search for a convenient substring in the window */
	offset = 0;
	length = 0;
	findLargest(in, inSize, p->window, WINDOWSIZE, &offset, &length);

	*inUsed = length;
	*outUsed = POINTERBYTES;

	if (length == 0) {
		offset = 0;  /* [should already be so] */
	}

	assert(POINTERBITS == 2 * 8);
	assert(POINTERBYTES == 2);
	assert(OFFSETBITS + LENGTHBITS == POINTERBITS);
	assert(OFFSETBITS - 8 >= 0);
	assert(LENGTHBITS >= 0);

	assert(offset >= 0);
	assert(offset < (1 << OFFSETBITS));
	assert(length >= 0);
	assert(length < (1 << LENGTHBITS));

	assert(out != NULL);

	/* encode offset and length */
	out[0] = (char)(offset >> (OFFSETBITS - 8));  /* high order offset */
	out[1] = (char)((offset << LENGTHBITS) | length);  /* low order offset and length */
}


/** Greedy search for largest substring [from beginning of string] in a
* window.
* Search forward and start at relative offset 0.
* Note: size may be 0.
*/
static void findLargest(
	char const* s,
	int size,
	char const* window,
	int windowSize,
	int* offset,
	int* length
)
{
	int r, m;

	assert(length != NULL);
	assert(offset != NULL);

	*length = 0;  /* maximal match length so far */
	*offset = 0;  /* match offset associated to length */

	for (r = 0; r < windowSize; r++) {  /* offset */
		m = matchLength(&window[r], windowSize - r, s, size);  /* [not considering the window as circular] */
		if (m > *length) {  /* prefer earlier matches [i.e. further from current position in this case] */
			*length = m;
			*offset = r;
		}
	}

	assert((*length == 0 && *offset == 0) || *length != 0);
}


/** Return length of a possible match.
* Note: the lengths may be zero.
*/
static int matchLength(char const* a, int an, char const* b, int bn)
{
	int n;

	assert(a != NULL);
	assert(b != NULL);

	n = 0;  /* match length */
	while (an-- > 0 && bn-- > 0 && *a++ == *b++) {
		n++;
	}

	return n;
}


/** Maximal input size that can be decoded by dictionary, in bytes, not
* depending on [current] dictionary state.
*/
static int maxDictionaryDecodingIn(void)
{
	/* decode-in size is the same as encode-out */
	return maxDictionaryEncodingOut();
}


/** Maximal output size in decoding by-dictionary, in bytes, not
* depending on [current] dictionary state.
*/
static int maxDictionaryDecodingOut(void)
{
	/* decode-out size is the same as encode-in */
	return maxDictionaryEncodingIn();
}


/** Decode by-dictionary.
*/
static void decodeByDictionary(
	lz77* p,
	char const* in,  /* input */
	int inSize,  /* input size, in bytes */
	int* inUsed,  /* returns the number of input bytes consumed after coding */
	char* out,  /* output buffer */
	int outSize,  /* output buffer size, bytes */
	int* outUsed  /* returns the number of output bytes generated by coding */
)
{
	int offset, length;

	assert(inUsed != NULL);
	assert(outUsed != NULL);

	*inUsed = 0;
	*outUsed = 0;

	assert(POINTERBITS == 2 * 8);
	assert(POINTERBYTES == 2);
	assert(OFFSETBITS + LENGTHBITS == POINTERBITS);
	assert(OFFSETBITS - 8 >= 0);
	assert(LENGTHBITS >= 0);
	assert(8 - LENGTHBITS >= 0);

	assert(in != NULL);

	assert(POINTERBYTES > 0);
	assert(inSize >= POINTERBYTES);

	/* [sanity check] */
	if (inSize < POINTERBYTES) {
		return;
	}

	/* decode offset and length */
	offset =
		((unsigned char)in[0] << (OFFSETBITS - 8)) |
		((unsigned char)in[1] >> LENGTHBITS);
	length = in[1] & ((unsigned char)0xff >> (8 - LENGTHBITS));

	assert(offset >= 0);
	assert(offset < (1 << OFFSETBITS));
	assert(length >= 0);
	assert(length < (1 << LENGTHBITS));

	assert(out != NULL);

	assert(outSize >= length);

	/* [sanity check] */
	if (outSize < length) {
		return;
	}

	assert(p != NULL);

	memmove(out, &p->window[offset], length);

	*inUsed = POINTERBYTES;
	*outUsed = length;
}


/** Update dictionary [model] with [some] input.
* Typically called after codeing, with inSize being equal to that inUsed.
*/
static void updateDictionary(
	lz77* p,
	char const* in,  /* input considered for model update, may not overlap with p->window */
	int inSize  /* size, bytes */
)
{
	/* Update dictionary [model] with [some] input. */

	assert(inSize >= 0);
	assert(in != NULL);

	assert(p != NULL);

	if (inSize >= WINDOWSIZE) {  /* new data fills whole window, old data [and possibly some new data] is discarded */
		assert(inSize - WINDOWSIZE >= 0);
		memmove(p->window, &in[inSize - WINDOWSIZE], WINDOWSIZE);
	} else if (inSize > 0) {  /* some old data needs to be discarded */
		/* Note: in order to support overlapping window and in,
		* we move in to the beginning of window first and then
		* rotate the window.
		*/
		assert(inSize <= WINDOWSIZE);
		memmove(p->window, in, inSize);
		memrot(p->window, WINDOWSIZE, inSize);
	}  /* else: inSize==0: nothing to do */
}


/** Rotate a memory buffer of specified size by n bytes to the left.
* Right-rotation is achieved by rotating it size-n.
* Element size can be a divisor of gcd(size,n).
*/
static void* memrot(void* p, int size, int n)
{
	int rounds;
	char *q, *e;

	if (size == 0) {  /* nothing to do; %size below would fail */
		return p;
	}

	n %= size;  /* adjust n to be 0<=n<size */
	if (n < 0) {  /* consider a possible negative n */
		n += size;
	}

	if (n == 0) {  /* nothing to do; rounds below would be large */
		return p;
	}

	q = (char*)p;  /* starting point for a round */
	e = q + size;  /* end of buffer, to wrap-adjust */
	rounds = gcd(size, n);  /* number of rounds needed to move memory */

	for (; rounds > 0; q++, rounds--) {
		char* r = q;
		char c = *r;  /* the one temporary location needed for moving the whole buffer */
		for (;;) {

			char* s = r + n;  /* next location to be moved */
			if (s >= e) {  /* consider wrap */
				s -= size;
			}

			if (s == q) {
				break;  /* done */
			}

			*r = *s;  /* move */
			r = s;  /* next */
		}
		*r = c;
	}

	return p;
}


/** Greatest common divisor of two integers.
* gcd(a,b) == gcd(b,a), gcd(a,0) == a.
*/
static int gcd(int a, int b)
{
	/* it is more convenient to have a>b
	* [otherwise the first remainder calculation just swaps them]
	*/

	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}

	return a;
}

