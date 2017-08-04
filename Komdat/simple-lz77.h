/* simple-lz77.h -- Simple LZ77 (Ziv-Lempel) encoding [compression] with
** fixed offset/legth sizes [fixed size window of 4096 {2**12} bytes,
** match lengths of 15 {2**4-1} bytes] and alternating pointers into the
** window dictionary and new symbols [characters].
** The implementation is not optimized for speed [but for simplicity of
** code and data structures].
**
** Copyright (C) 1992,2004 Eric Laroche.  All rights reserved.
**
** @author Eric Laroche <laroche@lrdev.com>, www.lrdev.com
** @version @(#)$Id: simple-lz77.h,v 1.1 2004/05/06 13:27:28 laroche Exp $
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


#ifndef SIMPLE_LZ77_H  /* multiple inclusion guard */
#define SIMPLE_LZ77_H


#include <stdio.h>  /* needed for FILE* */


/* opaque type, externally only used as pointer */
typedef struct lz77_st lz77;


/** Get a lz77 encoder.
* Initiates encoder's state (its dictionary).
* Returns NULL if memory allocation failed.
*/
lz77* lz77_new(void);


/** Dispose a lz77 encoder.
*/
void lz77_delete(lz77* p);


/** Encode a file stream with a lz77 encoder.
* Does not initiate encoder's state (its dictionary).
*/
void lz77_encode(lz77* p, FILE* in, FILE* out);


/** Decode a file stream with a lz77 decoder.
* Does not initiate decoder's state (its dictionary).
*/
void lz77_decode(lz77* p, FILE* in, FILE* out);


#endif

