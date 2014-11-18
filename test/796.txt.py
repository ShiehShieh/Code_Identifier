init=map(int,raw_input().split())
a=init[:10]
h=init[10]

h+=30
ans=0

for x in a:
	if h>=x:
		ans+=1

print '%d\n'%ans
