def main():
  n = int(raw_input())
  m = int(raw_input())
  dp = [0 for i in range(m + 1)]
  for i in range(1, n + 1):
    f, t = [int(x) for x in raw_input().split(' ')]
    for j in range(m, t - 1, -1):
      dp[j] = max(dp[j], dp[j - t] + f)
  print dp[m]

main()
