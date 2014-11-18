from decimal import *

def main():
    getcontext().prec = 200
    n, k = raw_input().split(' ')
    k = int(k)
    n = Decimal(n[-k:])
    periodCount = []
    # print n, k
    for i in range(k * 10 + 1):
        # print pow(n, i) % pow(10, k), n % pow(10, k)
        if (pow(n, i) % pow(10, k)) == (n % pow(10, k)):
            # print i
            periodCount.append(i)
            #return

    if periodCount:
        print periodCount[1] - periodCount[0]
    else:
        print -1
    
    return

main()
