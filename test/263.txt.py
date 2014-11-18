def g(n,m): return n if m==0 else g(m,n%m)
n,m=map(int,raw_input().split())
print n*m/g(n,m)