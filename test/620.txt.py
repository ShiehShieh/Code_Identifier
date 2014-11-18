x = int(raw_input())
l = 0
r = x
while(l <= r):
	t = (l + r) // 2
	u = t ** 3 + t ** 2 + t * 3 - x
	if(u > 0):
		r = t - 1
	else:
		l = t + 1
print(t)
