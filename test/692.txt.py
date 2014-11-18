from fractions import gcd
a=raw_input()
b=raw_input()
a=int(a)
b=int(b)
print a*b/gcd(a,b)