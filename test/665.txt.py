from decimal import *

getcontext().prec = 100
while True:
    try:
        r, n = raw_input().split()
    except EOFError:
        break
    r = Decimal(r)
    n = Decimal(n)
    s = str( r ** n)
    if s[0] == '0':
        print s[1:]
    else:
        print s
