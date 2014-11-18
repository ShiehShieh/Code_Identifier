import math
from decimal import *

def main():
    outList = []
    getcontext().prec = 500
    while True:
        testLine = raw_input()
        if len(testLine) == 0:
            break
        b = Decimal(testLine[testLine.rfind(" ") + 1:])
        tmp = testLine[:testLine.find(" ")]
        if tmp.find(".") != -1:
            while tmp[-1] == '0':
                tmp = tmp[0:-1]
        while tmp[0] == '0':
            tmp = tmp[1:]
        a = Decimal(tmp)
        out = str(pow(a, b))
        if out[0] == '0':
            out = out[1:]
        outList.append(out)
    for i in outList:
        print i
    return

main()
