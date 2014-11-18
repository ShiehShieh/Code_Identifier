def g(n,m): return n if m==0 else g(m,n%m)
def l(n,m): return n*m/g(n,m)
n,m=map(int,raw_input().split())
print l(n,m)