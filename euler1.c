#include <stdio.h>
#include <stdlib.h>
//Problem 1: multiples of 3 and 5
int main(){
	int max = 1000;
	int i; double sum;
	
	for (i=0;i<max; i++)
		if(i%3 == 0 || i%5==0)
			 sum+= (double) i;
	
	printf("%f\n", sum);
}
