import sys;
def gcd(a,b):
    if a%b: return gcd(b,r)
    else: return b

def lcm(a,b):
    return a*b/gcd(a,b)

n,m=map(int,sys.stdin.readline().split());

print lcm(n,m)