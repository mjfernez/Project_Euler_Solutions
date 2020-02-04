#include <stdio.h>
#include <stdlib.h>

long lpf(long num){
    long factor = 2;
    while(num > factor){
        if(num % factor == 0){
            num = num / factor;
            factor = 2;
        }
        else{
            factor ++;
        }
    }
    return factor;
}

int main(){
	printf("%d\n", lpf(600851475143));
	return 0;
}
