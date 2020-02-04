import PIL, math
#Problem 16 Power digit sum
n = 2**1000
strn = str(n)
s = 0

for i in strn:
	s += int(i)
	
print(s)
