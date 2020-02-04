import PIL, math

#Problem 4 - Palindrome Products

def isPalindrome(number):
	numchar = str(number)
	middle = len(numchar)/2
	face = numchar[:middle]
	ref = numchar[len(numchar):middle-1:-1]
	if(face == ref):
		return True
	else:
		return False

def findProduct(number):
	for i in range(999,100,-1):
		for j in range(999,100,-1):
			if(i*j==number):
				return [i,j]
			
def findMaxPalindrome():
	large = 0
	for i in range(999,100,-1):
		for j in range(999,100,-1):
			test = i*j
			if(isPalindrome(test) and test > large):
				large = test
	return large

answer = findMaxPalindrome()
print(answer)
print("The factors are: " + str(findProduct(answer)))
#x = input("Type a palindromic number: ")

#if(isPalindrome(x)):
	#print "The factors are: " + str(findProduct(x))
#else:
	#print "not a palindrome"

			
