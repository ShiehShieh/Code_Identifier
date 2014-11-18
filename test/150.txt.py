l,n=raw_input().split(" ")
f=[1]*(int(l)+1)
for i in range(0,int(n)):
  a,b=raw_input().split(" ")
  for j in range(int(a),int(b)+1):
    f[j]=0

total=0
for i in range(0,int(l)+1):
  if f[i]>0:
    total+=1
    
print total