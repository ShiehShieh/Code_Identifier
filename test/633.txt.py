d, a1, an = [float(x) for x in raw_input().split()]

f = [[0.0, 0.0, 0.0] for x in range(0, 70)]

f[0] = [2.0, 1.0, -2.0]
f[1] = [1.0, 0.0, 0.0]
f[2] = [0.0, 1.0, 0.0]

for i in range(3, n + 1):
    f[i][0] = f[i - 2][0] - 2 * f[i - 1][0]
    f[i][1] = f[i - 2][1] - 2 * f[i - 1][1]
    f[i][2] = f[i - 2][2] - 2 * f[i - 1][2] + 2

a2 = (an - f[n][0] * a1 - f[n][2] * d) / f[n][1]
am = f[m][0] * a1 + f[m][1] * a2 + f[m][2] * d

if abs(am) <= 1e-7:
    am = 0.0
print '%3.3f' % (am)
