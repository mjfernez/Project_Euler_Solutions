import PIL
import math

ones = ["", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"]
weirdos = ["thirteen", "twelve", "eleven", "ten"]
tens = ["", "teen", "twenty", "thirty", "forty",
        "fifty", "sixty", "seventy", "eighty", "ninety"]
nd = "AND"

#num must be less than 999#


def numToWord(num):
    digits = str(num)
    if (len(digits) == 1):  # one digit
        return ones[num]
    if (len(digits) == 2):  # two digits
        if(num < 14):  # special case for ten eleven twelve
            return weirdos[13 - num]
        if (num == 15):
            return "fifteen"
        if (num == 18):
            return "eighteen"
        t = digits[0]
        o = digits[1]
        if (int(t) == 1):
            return numToWord(int(o)) + tens[int(t)]
        else:
            return tens[int(t)] + numToWord(int(o))
    #number is three digits#
    h = digits[0]
    t = digits[1]
    o = digits[2]
    if(num % 100 == 0):
        return numToWord(int(h)) + "hundred"
    else:
        return numToWord(int(h)) + "hundred"+nd+numToWord(int(t+o))


n = int(input("Number: "))
out = ""
for i in range(1, n):
    out += numToWord(int(i))

out += "onethousand"
print(out)
print(str(len(out)) + " letters")
