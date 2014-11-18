from math import sqrt
N, R = raw_input().split(' ')
N, R = int(N), float(R)
point = []

for i in xrange(N):
	x, y = raw_input().split(' ')
	point.append( (float(x), float(y)) )

# print point
pi = 3.1416
length = 0.0
def dist(a, b):
	return sqrt((a[0] - b[0])**2 + (a[1]-b[1])**2)

if N == 1:
	length =  pi * 2 * R
else:
	for i in xrange(N-1):
		length += dist(point[i], point[i+1])
	length += (dist(point[0], point[-1]) + pi * 2 * R) 
print '%.2f' % length
