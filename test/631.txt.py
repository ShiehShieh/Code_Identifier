n, m = [int(x) for x in raw_input().split()]
d, a1, an = [float(x) for x in raw_input().split()]

f = [[0.0, 0.0] for x in range(0, 60)]

f[0] = [1.0, 2 * (a1 - d)]
f[1] = [0.0, a1]
f[2] = [1.0, 0.0]

for i in range(3, n + 1):
    f[i][0] = f[i - 2][0] - 2 * f[i - 1][0]
    f[i][1] = f[i - 2][1] - 2 * f[i - 1][1] + 2 * d

a2 = (an - f[n][1]) / f[n][0]
am = f[m][0] * a2 + f[m][1]

print '%3.3f' % (am)

