import PIL, math
import numpy as np

#Problem 7 - 10,001st prime

#returns a list of every prime up to a certain number
def listprimes(number):
	primes = []
	if (number <=1):
		return [1]
	a = np.ones(number)
	a[0]=0
	a[1]=0#1 and 0 are not prime
	##Sieve of eratosthenes
	for i in range(2,int(math.ceil(math.sqrt(number)))):
		if(a[i]==1):
			j = i**2 #cross out all the multiples of i, starting with its square
			while(j < number):
				a[j] = 0
				j+=i
	
	for k in range(2, number):
		#is prime
		if(a[k]==1):
			primes.append(k)
	return primes

out_list = listprimes(1000000)
print out_list
#return 10,001th prime factor
print out_list[10000]
