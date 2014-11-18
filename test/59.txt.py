n = input()
h = []
f = []

h = [int(x) for x in raw_input().split()]
for i in range(0, n):
    f.append([1, 1])

for i in range(0, n):
    for j in range(0, i):
        if h[j] < h[i] and f[j][0] + 1 > f[i][0]:
            f[i][0] = f[j][0] + 1

for i in range(n-1, -1, -1):
    for j in range(n-1, i, -1):
        if h[j] < h[i] and f[j][1] + 1 > f[i][1]:
            f[i][1] = f[j][1] + 1

mini = n

for i in range(0, n):
    if n - f[i][0] - f[i][1] + 1 < mini:
        mini = n - f[i][0] - f[i][1] + 1

print mini