R, C = raw_input().split()
R, C = int(R), int(C)

p = []
pp = []
xd = (-1, 0, 1, 0)
yd = (0, 1, 0, -1)
for  i in range(R):
	p.append(map(int, raw_input().split()))
	pp.append([0]*C)

def findp(i, j):
	if pp[i][j]>0:
		return pp[i][j]
	pp[i][j] = 1
	for k in range(4):
		t1 = i + xd[k]
		t2 = j + yd[k]
		if 0<=t1<R and 0<=t2<C and p[t1][t2]<p[i][j]:
			pp[i][j] = max(pp[i][j], findp(t1, t2) + 1)
	return pp[i][j]
maxl = 1
for i in range(R):
	for j in range(C):
		pp[i][j] = findp(i, j)
		if maxl<pp[i][j]:
			maxl = pp[i][j]

print maxl
