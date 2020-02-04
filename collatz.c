#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// Temporary storage chain
//long int *chain;
// The longest sequence found so far
//long int *seq;

// Size of the above arrays
long int c = 0;
long int s = 0;
long int collatz(long int seed){
    //chain = (long int *) realloc (chain, c * sizeof(long int));
    //chain[c - 1] == seed;
    c++;
    if(seed == 1)
        return 0;
    if(seed % 2 == 0)
        seed = seed / 2;
    else
        seed = 3 * seed + 1;
    //collatz(seed);
}

int main(){
    for(long int i = 1; i < pow(10, 6); i++){
        c = 0;
        //chain = (long int *) malloc(c * sizeof(long int));
        collatz(i);
        printf("%d \n", i);
        if(c > s){
            s = c;
        }
    }
    printf("Has %d numbers \n", s);
    return 0;
}
