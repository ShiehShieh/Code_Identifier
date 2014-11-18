n, m = [int(x) for x in raw_input().split()]
A = [[0 for j in range(m)] for i in range(n)]
f = [[0 for j in range(m)] for i in range(m)]
ans = 0
for i in range(n) :
    A[i] = [int(x) for x in raw_input().split()]
    f[0][m-1] = 0
    len = m-1
    while len > 0 :
        for j in range(m-len+1) :
            l = j
            r = j+len-1
            f[l][r] = 0
            if l - 1 >= 0 :
                if f[l-1][r] + A[i][l-1]*(2**(l+m-r-1)) > f[l][r] :
                    f[l][r] = f[l-1][r] + A[i][l-1]*(2**(l+m-r-1))
            if r + 1 < m :
                if f[l][r+1] + A[i][r+1]*(2**(l+m-r-1)) > f[l][r] :
                    f[l][r] = f[l][r+1] + A[i][r+1]*(2**(l+m-r-1))
        len -= 1
    now = 0
    for j in range(m) :
        if f[j][j] + A[i][j]*(2**m) > now :
            now = f[j][j] + A[i][j]*(2**m)
    ans += now
print ans
