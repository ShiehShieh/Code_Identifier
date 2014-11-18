def LCS(s1, s2):
  dp = [[0 for i in range(len(s2) + 1)] for j in range(len(s1) + 1)]
  for i in range(1, len(s1) + 1):
    for j in range(1, len(s2) + 1):
      if s1[i - 1] == s2[j - 1]:
        dp[i][j] = dp[i - 1][j - 1] + 1
      else:
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
  return dp[len(s1)][len(s2)]


def main():
  n = int(raw_input())
  for i in range(n):
    list1 = raw_input().split(' ', 1)[1].split(' ')
    list2 = raw_input().split(' ', 1)[1].split(' ')
    print LCS(list1, list2)

main()