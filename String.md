# [Data Structure: String](https://www.geeksforgeeks.org/string-data-structure/#reverse%20&%20rotation)

## Trivias

### Palindrome Checking

isPalindrome(str)
- Find length of str. Let length be n.
- Initialize low and high indexes as 0 and n-1 respectively.
- Do following while low index ‘l’ is smaller than high index ‘h’.
  - If str[l] is not same as str[h], then return false.
  - Increment l and decrement h, i.e., do l++ and h–.
- If we reach here, it means we didn’t find a miss


```cpp
#include <stdio.h>
#include <string.h>

// A function to check if a string str is palindrome
void isPalindrome(char str[])
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;

    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            printf("%s is Not Palindrome", str);
            return;
        }
    }
    printf("%s is palindrome", str);
}
```

## Print Palindromes from Given Range

Given a range of numbers, print all palindromes in the given range. For example if the given range is {10, 115}, then output should be {11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111}

```cpp
// A function to check if n is palindrome
int isPalindrome(int n)
{
    // Find reverse of n
    int rev = 0;
    for (int i = n; i > 0; i /= 10)
        rev = rev*10 + i%10;

    // If n and rev are same, then n is palindrome
    return (n==rev);
}

// prints palindrome between min and max
void countPal(int min, int max)
{
    for (int i = min; i <= max; i++)
        if (isPalindrome(i))
          cout << i << " ";
}
```

## [KMP: String Matching](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching)

Knuth-Morris-Pratt (KMP) string matching algorithm can perform the search in Ɵ( m + n ) operations.
```
Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
```
![kmp](assets/string/kmp.png)

```cpp
#include <bits/stdc++.h>

void computeLPSArray(char* pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver program to test above function
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
```

## Interesting Matters

- [Practice Questions on Strings](https://www.geeksforgeeks.org/problem-solving-strings/)
