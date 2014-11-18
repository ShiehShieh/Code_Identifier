f=[0]*30001
v=[0]*26
a=[0]*26
x,y=raw_input().split(" ")
t=int(x);n=int(y)
for i in range(1,n+1):
  x,y=raw_input().split(" ")
  a[i]=int(x);v[i]=int(y);

for i in range(1,n+1):
  for j in range(t,0,-1):
    if j>=a[i]:
      f[j]=max(f[j],f[j-a[i]]+v[i]*a[i])

print f[t]