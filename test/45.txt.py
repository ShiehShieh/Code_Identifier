def comb(i):
    while rel[i] != i:
        i = rel[i]

    return i

n, m, p = [int(t) for t in raw_input().split()]

rel = [x for x in range(0, n + 1)]
for i in range(0, m):
    a, b = [int(t) for t in raw_input().split()]
    rel[comb(a)] = rel[comb(b)]

for i in range(0, p):
    a, b = [int(t) for t in raw_input().split()]
    if comb(a) == comb(b):
        print "Yes"
    else:
        print "No"

