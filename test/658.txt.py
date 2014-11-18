from decimal import *

def main():
    getcontext().prec = 200
    n, k = raw_input().split(' ')
    k = int(k)
    periodCount = []

    i = 1
    while True:
        # k = 0
        tail = Decimal(n[-i:])
        tailPow = tail
        for j in range(2, 10 * i + 1):
            # k += 1
            # print i, k
            tailPow *= tail
            if (tailPow % pow(10, i)) == (tail % pow(10, k)):
                if i == k:
                    print j - 1
                    return
                else:
                    i += 1
                    break
            if j == 10 * i:
                i += 1
                break

main()
