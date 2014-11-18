def gcd(t):
    t.sort()
    k = t[1]%t[0]
    return t[0] if k == 0 else gcd([t[0],k])

a,b=(int(v) for v in raw_input().split(' '))
c=gcd([a,b])
print a/c*b