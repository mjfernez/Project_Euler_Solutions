#include <stdlib.h>
#include <stdio.h>

// num: the number to divide
// gd: the greatest divisor to count up to
int isDivisible(int num, int gd){
    int divisible = 1;
    for(int i = 1; i < gd; i++){
        if(num % i != 0)
            divisible = 0;
    }
    return divisible;
}

int main(){
    int found = 0;
    int start = 2520;
    while(!found){
        start += 20;
        found = isDivisible(start, 20); 
    }
    printf("%d\n", start);
}
