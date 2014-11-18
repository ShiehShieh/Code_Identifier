import sys

def SQR(x) :
    return x*x

def POW_10(x , P) :
    if x == 0 :
        return 1
    if x % 2 == 0 :
        return SQR(POW_10(x/2 , P)) % P
    else :
        return (10 * POW_10(x-1 , P)) % P

n, m, k, x = map(int,sys.stdin.readline().split())
print (x + m * POW_10(k , n)) % n
