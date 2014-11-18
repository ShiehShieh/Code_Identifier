def FUN(n, m) :
    ret = 1
    for i in range(0,m) :
        ret *= n-i
    for i in range(0,m) :
        ret /= i+1
    return ret

n, a, b = [int(x) for x in raw_input().split()]
print FUN(n+1+a-1,a) * FUN(n+1+b-1,b)
