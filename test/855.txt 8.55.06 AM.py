line = lambda: [int(s) for s in raw_input().split()]
n, m, p = line()
res = [[0] * (n + 1) for i in range(n + 1)]
for i in range(m):
        a, b = line()
        for c in range(n):
        	if res[a][c]: res[b][c] = res[c][b] = 1
        	if res[b][c]: res[a][c] = res[c][a] = 1
        res[a][b] = res[b][a] = 1
for i in range(p):
        a, b = line()
        print 'Yes' if res[a][b] else 'No'