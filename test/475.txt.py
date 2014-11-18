#!/usr/bin/env python2

n = input()
k = n // 3
r = n % 3

if r == 1:
    if k > 0:
        print(3 ** (k - 1) * 4)
    else:
        print(1)
elif r == 2:
    print(3 ** k * 2)
else:
    print(3 ** k)