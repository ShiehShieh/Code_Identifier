import sys;
def gcd(a, b):
    r = a % b
    if r: return gcd(b, r)
    else: return b

def lcm(a, b):
    return a * b / gcd(a, b)

n,m=map(int,raw_input().split());

print lcm(n,m)