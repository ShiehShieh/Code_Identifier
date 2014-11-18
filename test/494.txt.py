def main():
  bx, by, hx, hy = (int(x) for x in raw_input().split(' '))
  s = [[0 for i in range(by + 1)] for j in range(bx + 1)]
  s[0][0] = 1
  for i in range(bx + 1):
    for j in range(by + 1):
      if not (i == hx and j == hy or
                    abs(i - hx) == 1 and abs(j - hy) == 2 or
                    abs(i - hx) == 2 and abs(j - hy) == 1):
        if i > 0 and j > 0:
          s[i][j] = s[i - 1][j] + s[i][j - 1]
        elif i > 0:
          s[i][j] = s[i - 1][j]
        elif j > 0:
          s[i][j] = s[i][j - 1]
  print s[bx][by]


main()