n = input()

f = [x for x in range(0, n)]
f[0] = 1

for i in range(2, n):
    f[i] = (f[i - 2] + f[i - 1]) % 7654321

print f[n - 1]
