import sys
import math

n, r = sys.stdin.readline().strip().split();
n = int(n)
r = float(r)
points = []
for i in range(0, n):
	x, y = sys.stdin.readline().strip().split()
	points.append((float(x), float(y)))
len = 2 * math.pi * r
for i in range(0, n):
	x1, y1 = points[i]
	x2, y2 = points[i-1]
	len += math.sqrt((x1-x2)**2 + (y1-y2)**2)
print(round(len, 2))
