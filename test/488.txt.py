n, m = [int(x) for x in raw_input().split()]
A = []
C = [0 for i in range(400)]
for i in range(n) :
    x = input()
    A.append(x)
for i in range(m) :
    x = input()
    C[x] += 1
for i in range(n) :
    j = A[i] - 1
    while j > 0 and C[j] == 0 : j -= 1
    if j > 0 and C[j] > 0 :
        m -= 1
        C[j] -= 1
print m
