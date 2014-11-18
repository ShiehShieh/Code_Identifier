#!/usr/bin/python


l=input()
line=raw_input().split(' ')
s=int(line[0])
t=int(line[1])
m=int(line[2])
stone=raw_input().split(' ')
for i in xrange(m):
	stone[i]=int(stone[i])
stone.sort()

if (s<t):
	dis=t*t
	stone.append(l)
	for i in range(1,len(stone)):
		if (stone[i]-stone[i-1]-t>dis):
			stone[i]=stone[i-1]+t+1
	l=stone[len(stone)-1]

	list=[]
	if (stone[0]-t>dis):
		for i in xrange(t+1):
			list.append(0)
		list[t]=1
	else:
		for i in xrange(t+1):
			list.append(1000)
		list[t]=0
		for i in range(1,stone[0]+1):
			min=1000
			if i in stone:
				bool=1
			else:
				bool=0
			for k in range(s,t+1):
				if (list[t+1-k]+bool<min):
					min=list[t+1-k]+bool
			del list[0]
			list.append(min)
	for j in range(1,len(stone)):
		for i in range(stone[j-1]+1,stone[j]+1):
			min=1000
			if (i==stone[j]):
				bool=1
			else:
				bool=0
			for k in range(s,t+1):
				if (list[t+1-k]+bool<min):
					min=list[t+1-k]+bool
			del list[0]
			list.append(min)
	list[t]=list[t]-1
	min=1000
	for i in list:
		if (i<min):
			min=i
	print min
					
else:
	s=0
	for k in stone:
		if (k%s==0):
			s=s+1
	print s