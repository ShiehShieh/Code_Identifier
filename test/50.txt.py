cap = input()
n = input()

f = [0 for x in range(0, 22000)]
f[0] = 1

for i in range(0, n):
    w = input()
    for j in range(cap, -1, -1):
        if f[j] == 1 and j + w <= cap:
            f[j + w] = 1

for i in range(cap, -1, -1):
    if f[i] == 1:
        break

print cap - i
