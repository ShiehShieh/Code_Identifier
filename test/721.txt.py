data = raw_input().split('\n')

L = int(data[0])
S, T, M = data[1].split(' ')
S = int(S)
T = int(T)
M = int(M)
m = data[2].split(' ')
for i in xrange(M):
    m[i] = int(m[i])
dp = [0]*(L+1)
for i in range(S,T+1):
    if i in m:
        dp[i] = 1
for i in range(T+1, L+1):
    flag = 0
    minNum = 100000000000
    if i in m:
        flag = 1
    for j in range(S,T):
        if dp[i-j] < minNum:
            minNum = dp[i-j]
    dp[i] = minNum + flag
print dp[L]