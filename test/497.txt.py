n, m = [int(x) for x in raw_input().split(' ')]
dp = [[0 if i > 0 else 1 for i in range(n)], []]
k = 0
for i in range(m):
  dp[(k + 1) % 2] = [dp[k][(j + 1) % n] + dp[k][(j + n - 1) % n]
                     for j in range(n)]
  k = (k + 1) % 2
print dp[k][0]
