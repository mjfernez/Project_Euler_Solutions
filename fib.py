import PIL
import math
MAX = 4*10**6

# Problem 2 Even Fibonnacci numbers
fib = [1, 1]

k = 1
while (True):
    n = fib[k] + fib[k-1]
    if(n > MAX):
        break
    else:
        fib.append(n)
        k += 1

c = 0
for i in fib:
    num = str(i)
    print(num + " ", end='')
    c += 1
    if(c % 10 == 0):
        print()

print()

print("The sum is: " + str(sum(fib)))

s = 0
for i in fib:
    if (i % 2 == 0):
        s += i

print("The sum of the even terms is: " + str(s))
