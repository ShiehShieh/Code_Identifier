v=input()
n=input()
f=[0 for i in range(0,20010)]
a=[0 for i in range(0,40)]
for i in range(1,n+1):
  a[i]=input()

for i in range(1,n+1):
  for j in range(v+1,0,-1):
    if j-a[i]>=0:
      f[j]=max(f[j],f[j-a[i]]+a[i])
    
print v-f[v]