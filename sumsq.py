#The sum of the squares of the first ten natural numbers is,
#12 + 22 + ... + 102 = 385
#The square of the sum of the first ten natural numbers is,
#(1 + 2 + ... + 10)2 = 552 = 3025
#Hence the difference between the sum of the squares 
#of the first ten natural numbers and the square of the sum is 
#Find the difference between the sum of the squares of the first 
#one hundred natural numbers and the square of the sum.

import PIL, math
import numpy as np

nums = range(1,11)
numsq = range(1,11)

for i in nums:
	i = i*i

print nums
print numsq

sum1 = (sum(nums)**2)
sum2 = (sum(numsq))

print "The sum squared is: " + str(sum1)
print "The sum of the squares is: " + str(sum2)

print "The difference is: " + str(abs(sum2-sum1))