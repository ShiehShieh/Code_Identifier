init=raw_input().split()
a=map(int,init[:10])
h=int(init[10])

h+=30
ans=0

for x in a:
	if h>=x:
		ans+=1

print ans
