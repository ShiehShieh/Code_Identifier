#include <iostream>
#define MAX 10002
using namespace std;
int dp[27][MAX],v[27],p[27];
int GetMax(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int N,m,i,j;
	while(scanf("%d%d",&N,&m)!=EOF)
	{
		for(i=1;i<=m;i++)
			scanf("%d%d",&v[i],&p[i]);
		for(i=1;i<=N;i++)
		{
			if(i>=v[m])
				dp[m][i]=v[m]*p[m];
			else
				dp[m][i]=0;
		}
		for(i=m-1;i>=2;i--)
			for(j=1;j<=N;j++)
			{
				if(j>=v[i])
					dp[i][j]=GetMax(dp[i+1][j],dp[i+1][j-v[i]]+v[i]*p[i]);
				else
					dp[i][j]=dp[i+1][j];
			}
		dp[1][N]=dp[2][N];
		if(N>v[1])
			dp[1][N]=GetMax(dp[2][N],dp[2][N-v[1]]+v[1]*p[1]);
		printf("%d\n",dp[1][N]);
	}
	return 0;
}
