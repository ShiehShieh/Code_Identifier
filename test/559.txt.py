n,m=[int(i) for i in raw_input().split()]
dp=[0]*100;
dp[-1]=1;
dp[0]=1;
for i in range(1,n+1):
	if i<m: dp[i]=dp[i-1]*2
	else: dp[i]=dp[i-1]*2-dp[i-m-1];
print dp[n]
