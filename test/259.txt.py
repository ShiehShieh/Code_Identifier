def c(u,v):
	return u[0]*u[1]-v[0]*v[1]
n=int(raw_input())
l=[]
p,v=map(int,raw_input().split())
i=0
while(i<n):
	l.append(map(int,raw_input().split()))
	i+=1
l.sort(c)
i=m=0
while(i<n):
	m=max(m,int(p/l[i][1]))
	p*=l[i][0]
	i+=1
print m