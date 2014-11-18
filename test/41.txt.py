n = input()

f = [0 for x in range(0, 1200)]

for i in range(1, n + 1):
    f[i] = 1 + sum(f[:i / 2 + 1])

print f[n]
