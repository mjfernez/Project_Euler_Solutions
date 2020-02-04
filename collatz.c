#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// In C, it's immediately obvious my python solution is inefficient

// For keeping track of the length of sequences
// c is a temporary counter, s changes when c reaches a new maximum
long int c = 0;
long int s = 0;
long int collatz(long int seed){
    c++;
    if(seed == 1)
        return 0;
    if(seed % 2 == 0)
        seed = seed / 2;
    else
        seed = 3 * seed + 1;
    collatz(seed);
}

int main(){
    for(long int i = 1; i < pow(10, 6); i++){
        c = 0;
        collatz(i);
        if(c > s){
            s = c;
        }
    }
    printf("The longest sequence has %d numbers \n", s);
    return 0;
}
