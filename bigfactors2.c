#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int countFactors(int num){
	int factors = 0;
    // Check only up until the square root of the number
 	int root = (int) ceil(sqrt(num));
    //printf("%d\n", root);
    for(int i = 2; i < root; i++){
        if(num % i == 0)
            factors+=2;
    }
    // Correction for perfect square
    if(root * root == num)
        factors -= 1;
    return factors;
}

int main(){
	int i = 1;
	int k = 1;
	int j = 0;
	while(k < 500){
		j += i;
		k = countFactors(j);
		i += 1;
	}
	printf("%d has over 500 factors. Neat!\n", j);
	return 0;
}
