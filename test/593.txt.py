n = int(raw_input())
A, B = raw_input().split()

p = []

for i in range(0, n):
	p1, p2 = raw_input().split()
	p.append((int(p1) * int(p2), int(p1), int(p2)))

p.sort()
tmp = int(A)
Ans = tmp/p[0][2]
for i in range(1, n):
	tmp*= p[i-1][1]
	Ans = max(Ans, tmp/p[i][2])

print Ans
