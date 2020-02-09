# A Pythagorean triplet is a set of three natural numbers,
# a < b < c, for which,
# a2 + b2 = c2
# For example, 32 + 42 = 9 + 16 = 25 = 52.
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.

import PIL
import math


def isTriple(abc):
    if len(abc) > 3:
        return False
    legs = abc[0]**2 + abc[1]**2
    hyp = abc[2]**2

    if (hyp == legs):
        return True
    else:
        return False


for i in range(1, 1000):
    for j in range(1, 1000):
        for k in range(1, 1000):
            if (i+j+k) == 1000 and isTriple([i, j, k]):
                print([i, j, k])
                print(i*j*k)
                exit()
