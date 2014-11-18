import math

n, r = [float(t) for t in raw_input().split()]
n = int(n)

data = []
for i in range(0, n):
    data.append([float(t) for t in raw_input().split()])

l = 0.0
for i in range(0, n):
    l = l + math.sqrt(math.pow(data[i][0] - data[i - 1][0], 2) \
            + math.pow(data[i][1] - data[i - 1][1], 2))

l = l + 2 * math.pi * r

print '%2.2f' % (l)
