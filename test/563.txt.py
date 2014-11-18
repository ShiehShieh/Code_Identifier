n,m=map(int,raw_input().split());k=sorted([map(int,raw_input().split()) for i in range(n)],key=lambda x:-x[1]*100000+x[0])
j=m*3/2-1;s=k[j][1]
while j<n and s==k[j][1]:j+=1
print s,j
for i in range(j):print k[i][0],k[i][1]