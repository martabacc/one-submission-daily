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
