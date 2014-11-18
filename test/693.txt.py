f=[[0]*1001]*101
v=[0]*101
a=[0]*101
x,y=raw_input().split(" ")
t=int(x);n=int(y)
for i in range(0,n):
  x,y=raw_input().split(" ")
  a[i]=int(x);v[i]=int(y);

for i in range(1,n+1):
  for j in range(t+1,0,-1):
    if j>=a[i]:
      f[i][j]=max(f[i-1][j],f[i][j-a[i]]+v[i])

print f[n][t]