import math
from decimal import *

def main():
    getcontext().prec = 100
    while True:
        testLine = raw_input()
        if len(testLine) == 0:
            break
        b = Decimal(testLine[testLine.rfind(" ") + 1:])
        a = Decimal(testLine[:testLine.find(" ")])
        out = str(pow(a, b))
        if out[0] == '0':
            out = out[1:]
        print out
main()
