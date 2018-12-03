import PIL, math
import numpy as np
#Problem 3 Largest Prime Factor

###INEFFICIENT METHODS###
#def isPrime(number):
#	if (number <=1):
#		return False
#	for i in range(2,number):
#		if(number%i==0):
#			return False
#	return True

#def prime_factors(number):
	#primes = []
	#for i in range(number, 2, -1):
		#if(number%i==0):
			#if (isPrime(i)):
				#return i
	#return primes



def prime_factors(number):
	primes = []
	if (number <=1):
		return [1]
	a = np.ones(number)
	a[0]=0
	a[1]=0#not prime
	for i in range(2,int(math.ceil(math.sqrt(number)))):
		if(a[i]==1):
			j = i**2 #cross out all the multiples
			while(j < number):
				a[j] = False
				j+=i
	
	for k in range(2, number):
		#is prime		is a factor
		if(a[k]==1) and (number%k==0):
			primes.append(k)
	return primes
	
def lpf(number):
	factor = 2
	while (number > factor):
		if(number % factor == 0):
			number = number/factor
			factor = 2
		else:
			factor +=1
	return factor
			
out = lpf(600851475143)
print out
