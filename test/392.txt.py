# {B[i]} non-decreasing
# B[0]=0, B[N]=N
# B[i+1]-B[i] \in {0,1,2}
# each increasing provides one restriction for one digit

# F[i] denote the answer for the first B[i] restricted numbers

def Solve(n, a):
    f = [0]*(n+1)
    f[0] = 1
    for i in range(n):
        if a[i] == a[i+1]:
            f[i+1] = f[i]
        elif a[i+1] == a[i] + 1:
            f[i+1] = f[i] * ((i + 1 - a[i]) * 2 - 1)
        elif a[i+1] == a[i] + 2:
            f[i+1] = f[i] * (i - a[i]) * (i - a[i])
        # print i, f[i]
    return f[n]

import sys
n = input()
a = [0]*(n+1)
a[0] = 0
a[1:n+1:1] = map(int,sys.stdin.readline().split())
print Solve(n, a)
