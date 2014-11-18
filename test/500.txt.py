C = [[0 for j in range(201)] for i in range(201)]

def Pre() :
    C[0][0] = 1
    for i in range(1,201) :
        C[i][0] = 1
        C[i][i] = 1
        for j in range(1,i) :
            C[i][j] = C[i-1][j-1] + C[i-1][j]

def FUN(n, x, t) :
    if n == 0 :
        return 0, 0
    else :
        totone, ret = FUN(n/2, x, t+1)
        if n % 2 == 0 :
            return totone, ret
        else :
            if totone <= x :
                ret += C[t][x-totone]
            return totone+1, ret

def Solve(n, x) :
    totone, ret = FUN(n, x, 0)
    return ret

Pre()
n = input()
ans = n*(n+3)/2
for i in range(1,170) :
    ans -= (2**i) * Solve(n+1, i)
print ans
