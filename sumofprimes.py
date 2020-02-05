import PIL
import math

# Problem 10 sum of primes

def prime_factors(number):
    primes = []
    if (number <= 1):
        return [1]
    a = [1] * number
    a[0] = 0
    a[1] = 0  # not prime
    for i in range(2, int(math.ceil(math.sqrt(number)))):
        if(a[i] == 1):
            j = i**2  # cross out all the multiples
            while(j < number):
                a[j] = False
                j += i

    for k in range(2, number):
        # is prime
        if(a[k] == 1):
            primes.append(k)
    return primes


out = prime_factors(2000000)
print(str(sum(out)))
