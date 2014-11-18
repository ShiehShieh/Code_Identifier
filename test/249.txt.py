L, M = [int(x) for x in raw_input().split()]

tree = [0 for x in range(L + 1)]

for i in range(M):
    s, e = [int(x) for x in raw_input().split()]
    for j in range(s, e + 1):
        tree[j] = 1

left = 0

for i in tree:
    if i == 0:
        left += 1

print left



