R, C = raw_input().split()
R, C = int(R), int(C)

p = []
for  i in xrange(R):
	p.append(map(int, raw_input().split()))

#print p
def find(i, j, n):
	global nm
	if i-1>=0 and p[i][j] > p[i-1][j]:
		#print i-1,j,p[i-1][j]
		find(i-1, j, n+1)
	if i+1<=C-1 and (p[i][j] > p[i+1][j]):
		#print i+1,j,p[i+1][j]
		find(i+1, j, n+1)
	if j-1>=0 and p[i][j] > p[i][j-1]:
		#print i,j-1,p[i][j-1]
		find(i, j-1, n+1)
	if j+1<=R-1 and p[i][j] > p[i][j+1]:
		#print i,j+1,p[i][j+1]
		find(i, j+1, n+1)
	#print n,'-------<F6>'
	if n>nm:
		nm = n
max = 0
for i in xrange(R):
	for j in xrange(C):
		nm = 1
		find(i, j, 1)
		#print mn
		if nm>max:
			max = nm
print max
