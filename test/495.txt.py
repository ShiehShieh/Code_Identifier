def main():
  n, m = [int(x) for x in raw_input().split(' ')]
  a = [int(x) for x in ("0 " + raw_input()).split(' ')]
  dp = [[0 for i in range(m + 1)] for j in range(n + 1)]
  dp[0][0] = 1
  for i in range(0, n + 1):
    for j in range(a[i] + 1):
      for k in range(j, m + 1):
        dp[i][k] += dp[i - 1][k - j]
        dp[i][k] %= 1000007
  print dp[n][m]

main()