t, m = [int(inp) for inp in raw_input().split()]

bag = [0 for x in range(0, 2000)]

for i in range(0, m):
    w, v = [int(inp) for inp in raw_input().split()]
    for j in range(t, -1, -1):
        if j == 0 or bag[j] > 0:
            if j + w <= t and bag[j] + v > bag[j + w]:
                bag[j + w] = bag[j] + v


maxv = 0
for i in range(0, t + 1):
    if bag[i] > maxv:
        maxv = bag[i]

print maxv
