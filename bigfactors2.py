import PIL, math
import numpy as np

#Problem 12 Highly divisible triangular number
#finds the first number with over 500 factors

def countfactors(num):
	factors = 0
	### we only need to know about the FIRST HALF of factors,
	##one factor implies a second
	root = int(math.ceil(math.sqrt(num)))
	divs = range(1, root)
	for d in divs:
		if(num%d == 0):
			factors += 2
			
	#Correction if the number is a perfect square
	if (root * root == num):
		factors-=1
	return factors


####   MAIN #####
i=1
k=1
j = 0
while(k < 500):
	j += i
	k=countfactors(j)
	print str(j) + " has " + str(k) + " factors"
	i += 1
