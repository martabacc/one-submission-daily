# Second

It should print from 1 to 100 and reach both ends. Find whats wrong with this code by **only changing one line**.

## C++

```
#include <stdio.h>
int main() {
    int i;
    for (i=1; i<=100; i++) {
        if (i % 15 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else{
            printf("%d\n", i);
        }
    }
}
```