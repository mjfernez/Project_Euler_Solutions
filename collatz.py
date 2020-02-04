import PIL, math

#Problem 14 Longest Collatz sequence
#Note, a little slow, takes about 15 seconds. 
#There is probably a more efficient solution out there
chain = []
biggo = []

def collatz(seed):
	chain.append(seed)
	if(seed == 1): return 0
	if(seed%2 == 0):
		seed = seed/2
	else:
		seed = 3*seed +1
	collatz(seed)

for n in range(1,pow(10,6)):
	collatz(n)
	if(len(chain)>len(biggo)):
		biggo = chain
	chain = []
print(biggo)
print("Has " + str(len(biggo)) +" numbers.")
