def gcd(x, y) :
    if y == 0 : return x
    else : return gcd(y, x%y)

n = input()
a, b, c = 0, 0, 1

for i in range(1,n+1) :
    # a + b/c + n/i = a + (bi+nc)/(ci)
    b, c = b*i+n*c, c*i
    # a += b/c
    # b %= c
    # g = gcd(b, c)
    # b, c = b/g, c/g

a = b/c
b %= c
g = gcd(b, c)
b, c = b/g, c/g

if b == 0 :
    print a
else :
    print ' '*len(str(a))+str(b)
    print str(a)+'-'*max(len(str(b)),len(str(c)))
    print ' '*len(str(a))+str(c)
