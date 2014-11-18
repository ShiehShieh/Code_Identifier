n=int(raw_input())
l=1
r=n
t=0
while l<=r:
  mid=(l+r)>>1
  if mid*mid<=n:
    t=mid
    l=mid+1
  else:
    r=mid-1
print t