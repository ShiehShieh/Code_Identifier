n=int(raw_input())
a=[]
a.append(1)
a.append(2)
a.append(3)
for i in range(3,n):a.append(max(a[i-2]*2,a[i-3]*3))
print a[n-1]
