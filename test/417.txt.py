def f(x) :
    return x ** 3 + x * x + x * 3

a = int(input())
l = 0
r = a
while l != r :
    m = (l + r + 1) >> 1
    if f(m) <= a :
        l = m
    else :
        r = m - 1
print l
