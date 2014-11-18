import fractions
a,b = map(int, raw_input().split())
c = a * b / fractions.gcd(a,b)
print c
