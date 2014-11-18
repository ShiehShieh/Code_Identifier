n = input()

f = [[0, 0, 0, 0] for x in range(0, n)]
f[0][0] = 1

for i in range(1, n):
    f[i][2] = f[i][2] + f[i - 1][0] + f[i - 1][3]
    f[i][3] = f[i][3] + f[i - 1][1] + f[i - 1][2]
    f[i][0] = f[i][0] + f[i - 1][2]
    f[i][1] = f[i][1] + f[i - 1][3]

print sum(f[n - 1])
