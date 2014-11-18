import sys
import math

length = int(sys.stdin.readline().strip())
short, long = (int(x) for x in sys.stdin.readline().strip().split()[:2])
stones = [int(x) for x in sys.stdin.readline().strip().split()]
stones.sort()
comp = [0] + stones + [length]
for i in range(len(comp)-1):
	if short == long:
		blank = ((comp[i+1] - comp[i]) // short) * short
	else:
		free = (int(math.ceil((long-1)/(long-short))) - 1) * short
		blank = (comp[i+1] - comp[i] - free - 1) if comp[i+1] - comp[i] > free + 1 else 0
	comp = comp[:i+1] + [x-blank for x in comp[i+1:]]
stones = comp[1:-1]
length = comp[-1]
dp = [-1] * length
for i in range(length-1, -1, -1):
	if i+long >= length:
		dp[i] = 0
	else:
		dp[i] = min([dp[j] + (1 if j in stones else 0) for j in range(i+short, i+long+1)])
print(dp[0])
