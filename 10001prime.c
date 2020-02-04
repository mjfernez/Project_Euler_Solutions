#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n = 1000000;

int *listPrimes(int num){
	int i;
	int *primes;
	int *sieve = (int *) malloc(num * sizeof(int));
	//initialize to all 1s (except 0 and 1 which are not prime)
	for(i = 2; i < num; i++)
		sieve[i] = 1;
	for(i = 2; i < ceil(sqrt(num)); i++){
		if(sieve[i] ==  1){
			int j = i * i;
			while(j < num){
				sieve[j] = 0;
				j += i;
			}
		}
	}
	
	//now check which were prime
	int s = 0;
	primes = (int *) malloc(sizeof(int));
	for(i = 2; i < num; i++){
		if(sieve[i]){
			primes[s] = i;
			s++;
			primes = (int *) realloc (primes, (s + 1) * sizeof(int));
		}
	}

	return primes;
}

int main(){
	int *p = listPrimes(n);
	int prime10001 = p[10000];
	printf("%d\n", prime10001);
	return 0;
}
