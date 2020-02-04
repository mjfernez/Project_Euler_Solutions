#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isPalindrome(long num){
    long len = 0;
    long n = num;
    while(n != 0){
        n = n / 10;
        len++;
    }
    char *numchar = (char *) malloc (len * sizeof(char));
    sprintf(numchar, "%ld", num);
    //printf("%s\n", numchar);
    // Backwards counter
    long j = len - 1;
    // Forwards counter
    long i = 0;

    while(i < len){
        if(numchar[i] != numchar[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

long *findProduct(long num){
    for(long i = 999; i > 100; i--)
        for(long j = 999; j > 100; j--)
            if(i * j == num){
                long *facts = (long *) malloc (2 * sizeof(long));
                facts[0] = i;
                facts[1] = j;
                return facts;
            }
}

long findMaxPalindrome(){
    long large = 0;
    for(long i = 999; i > 100; i--){
        for(long j = 999; j > 100; j--){
            long test = i * j;
            if(isPalindrome(test) && test > large){
                large = test;
            }
        }
    }
    return large;
}

int main(){
    long answer = findMaxPalindrome();
    printf("%d\n", answer);
    long *prod = findProduct(answer);
    printf("The factors are %d and %d\n", prod[0], prod[1]);
}

