def sc_xy(m,n):
	a,b = divmod(m,2)
	c,d = divmod(n,2)
	if (b == 0 and d == 0): return a,c,2
	a,b = divmod(m,3)
	c,d = divmod(n,3)
	if (b == 0 and d == 0): return a,c,3
	a,b = divmod(m,5)
	c,d = divmod(n,5)
	if (b == 0 and d == 0): return a,c,5
	a,b = divmod(m,7)
	c,d = divmod(n,7)
	if (b == 0 and d == 0): return a,c,7
	return m,n,-1
a,b = raw_input().split()
a = int(a)
b = int(b)
res = 1
while(True):
	a,b,t = sc_xy(a,b)
	if (t == -1):
		res *= a * b
		break
	res *= t
print(res)