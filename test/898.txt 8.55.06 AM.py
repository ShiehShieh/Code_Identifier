R, C = raw_input().split()
R, C = int(R), int(C)

p = []
pp = []
for  i in xrange(R):
	p.append(map(int, raw_input().split()))
	pp.append([0]*C)

def find(i, j):
	nn = 0
	l=[1]
	if i-1>=0 and p[i][j] > p[i-1][j]:
		if pp[i-1][j]:
			nn = 1 + pp[i-1][j]
		else:
			nn = 1 + find(i-1, j)
		l.append(nn)
	if i+1<=C-1 and (p[i][j] > p[i+1][j]):
		if pp[i+1][j]:
			nn = 1 + pp[i+1][j]
		else:
			nn = 1 + find(i+1, j)
		l.append(nn)
	if j-1>=0 and p[i][j] > p[i][j-1]:
		if pp[i][j-1]:
			nn = 1 + pp[i][j-1]
		else:
			nn = 1 + find(i, j-1)
		l.append(nn)
	if j+1<=R-1 and p[i][j] > p[i][j+1]:
		if pp[i][j+1]:
			nn = 1 + pp[i][j+1]
		else:
			nn = 1+ find(i, j+1)
		l.append(nn)
	return max(l)	
ma = 1
for i in xrange(R):
	for j in xrange(C):
		nm = 1
		pp[i][j] = find(i, j)
		if pp[i][j]>ma:
			ma = pp[i][j]
print ma
