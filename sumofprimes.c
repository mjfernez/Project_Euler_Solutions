#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The number to find primes up to
int n = 2000000;

// The number of primes in the primes array
int s = 0;

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
    long long sum = 0;
    int len = s;
    for(int i = 0; i < s; i++){
        sum += p[i];
    }
	printf("%ld\n", sum);
	return 0;
}
