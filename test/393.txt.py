import sys

def FindPrimes(n) :
    P = []
    f = []

    for i in range(n+1): f.append(0)
    i = 2
    while i <= n:
        if f[i] == 0:
            j = i*2
            while j <= n:
                f[j] = 1
                j += i
        i += 1

    P = []
    for i in range(2,n):
        if f[i] == 0:
            P.append(i)

    return P

def Power(a, b):
    if b == 0 : return 1
    if b % 2 == 0 :
        return Power(a, b/2)**2  % (10**100)
    else :
        return a * Power(a, b-1) % (10**100)

def C(n, m, P) :
    h   = [0]*(100010)
    Cnt = [0]*(len(P))
    for i in range(n,n-m,-1) :
        tmp = i
        for j in range(len(P)) :
            while tmp % P[j] == 0 :
                Cnt[j] += 1
                tmp /= P[j]
            if tmp == 1 : break
        h[tmp] += 1
    for i in range(1,m+1) :
        tmp = i
        for j in range(len(P)) :
            while tmp % P[j] == 0 :
                Cnt[j] -= 1
                tmp /= P[j]
            if tmp == 1 : break
        h[tmp] -= 1
    ret = 1
    for i in range(len(P)) :
        ret = (ret * Power(P[i],Cnt[i])) % (10**100)
    for i in range(1,100000) :
        while h[i] > 0 :
            ret = (ret * i) % (10**100)
            h[i] -= 1
    return ret

n = 350
P = FindPrimes(n)

n, m = map(int,sys.stdin.readline().split())
ans = C(n+m, m, P)
a = [0]*11
for i in range(11):
    a[i] = (10**10)**i
for i in range(10):
    tmp = (ans % a[10-i]) / a[9-i]
    for i in range(9):
        if tmp < (10**(i+1)):
            sys.stdout.write("0")
    print tmp
