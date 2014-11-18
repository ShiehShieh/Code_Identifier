n, k = ((int(x) for x in raw_input().split(' ')))
nums = raw_input()

dp = [[0 for i in range(k + 1)] for j in range(n + 1)]

for i in range(n):
  dp[i][0] = int(nums[:i + 1])
  for j in range(1, k + 1):
    for p in range(i):
      dp[i][j] = max(dp[i][j], dp[p][j - 1] * int(nums[p + 1:i + 1]))

print dp[n - 1][k]
