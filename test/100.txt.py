N = int(raw_input())
M = int(raw_input())
T = {}
S = []
f = 0
for i in range(0,M):
    j = int(raw_input())
    k = j%N
    if (k==0) and (j!=0):
        f = j
        break
    S.append(j)
    T[k] = str(j)
S.sort()
r = 1
while(f==0):
    t = {}
    r = r * 10 % N
    s = [((v * r) % N) for v in S]
    for i in range(0,M):
        j = N - s[i]
        if j in T:
            f = int(str(S[i])+T[j])
            break
    if f != 0:
        break
    for i in range(0,M):
        for x in T:
            u = (x+s[i])%N
            if not (u in t):
                t[u] = str(S[i]) + T[x]
    T = t
print f