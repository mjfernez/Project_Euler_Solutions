#Problem 5 smallest multiple
#2520 is the smallest number that can be divided by 
#each of the numbers from 1 to 10 without any remainder.
#What is the smallest positive number that is evenly divisible 
#by all of the numbers from 1 to 20?

import PIL, math

def isDivisible(num, divisors):
	divisible = True
	for j in divisors:
		if(num%j !=0):
			divisible = False
			break
	return divisible

divs = range(1,21)

found = False
start = 2520
while (not found):
	start+=20
	found = isDivisible(start,divs)
	
print(start)
print(str(isDivisible(start, divs)))
