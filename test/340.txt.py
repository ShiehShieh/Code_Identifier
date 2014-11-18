n=int(raw_input())
#p^3+p^2+3p<=n
def f(x):
    return x**3+x**2+3*x-n
def ff(x):
    return 3*x**2+2*x+3
l=0
r=n+1
while l<r:
    mid=(l+r)//2
    if(f(mid)>0):
        r=mid
    else:
        l=mid+1
print l-1
    
