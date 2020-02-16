#include <stdio.h>

// Find the difference between (1+2+3+...+100)^2 and (1^2+2^2+3^2+...+100^2)
// I used another math trick here:
// The sum up to a number can be found using Gauss' Trick:
// 1 + 2 + 3 + ... + 10 -> (1+9) + (2+8) + (3+7) + (4+6) + 10 + 5 -> 5*10 +5
// In general : (n/2)(n+1)

int main() {
    long sqsum = 50 * 101;
    sqsum *=sqsum;
    printf("The square of the sum is: %lu\n", sqsum);
    long sumsq = 0;
    for(long i = 1; i <= 100; i++) {
        sumsq += i * i;
    }
    printf("The sum of the squares is: %lu\n", sumsq);
    printf("Difference: %lu\n", sqsum - sumsq);
    return 0;
}
