size, n = input(), input()
dp = [0 for i in range(size + 1)]
for i in range(1, n + 1):
  v = input()
  for j in range(size, v - 1, -1):
    dp[j] = max(dp[j], dp[j - v] + v)
print size - dp[size]
