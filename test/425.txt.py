MAXN = 100

F = [[0 for col in range(MAXN+1)] for row in range(MAXN+1)]

for i in range(1,MAXN+1) :
    F[i][1] = 1
    F[i][i] = 1
    for j in range(2,i) :
        F[i][j] = F[i-1][j] * j + F[i-1][j-1]

while True :
    line = raw_input()
    if not line :
        break
    else :
        n, m = [int(s) for s in line.split()]
        print F[n][m]
