import sys;
def gcd(a, b):
    r = a % b
    if r: return gcd(b, r)
    else: return b

def lcm(a, b):
    return a * b / gcd(a, b)

n=int(raw_input())
m=int(raw_input())

print lcm(n,m)
