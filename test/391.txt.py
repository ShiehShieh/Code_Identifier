def f(x):
    return x**3 + x**2 + 3*x

def Solve(n):
    l = 0
    r = n
    while l < r:
        mid = (l+r+1)/2
        if f(mid) <= n:
            l = mid
        else:
            r = mid - 1
    return l

import sys
n = input()
print Solve(n)
