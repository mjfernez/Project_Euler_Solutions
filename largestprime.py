import PIL
import math
# Problem 3 Largest Prime Factor
def lpf(number):
    factor = 2
    while (number > factor):
        if(number % factor == 0):
            number = number/factor
            factor = 2
        else:
            factor += 1
    return factor


out = lpf(600851475143)
print(out)
