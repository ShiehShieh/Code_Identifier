def gcd(m, n):
    while n:
        m, n = n, m % n
    return m

def lcm(m, n):
    return m * n / gcd(m,n)

import sys
a, b = map(int,sys.stdin.readline().split())
print lcm(a,b)
