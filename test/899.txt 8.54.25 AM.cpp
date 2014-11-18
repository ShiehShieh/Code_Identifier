#include <iostream>
using namespace std;
int dp[101][1001],v[101],t[101];
int GetMax(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int M,T,i,j;
	while(scanf("%d%d",&T,&M)!=EOF)
	{
		for(i=1;i<=M;i++)
			scanf("%d%d",&t[i],&v[i]);
		for(i=0;i<=T;i++)
		{
			if(i>=t[M])  //因为我要逆向做0-1背包,所以我从t[M]开始判断
				dp[M][i]=v[M];
			else
				dp[M][i]=0;
		}
		for(i=M-1;i>=2;i--)
			for(j=1;j<=T;j++)
			{
				if(j>=t[i])
					dp[i][j]=GetMax(dp[i+1][j],dp[i+1][j-t[i]]+v[i]);
				else
					dp[i][j]=dp[i+1][j];
			}
		dp[1][T]=dp[2][T];
		if(T>=t[1]) 
			dp[1][T]=GetMax(dp[1][T],dp[2][T-t[1]]+v[1]);
		printf("%d\n",dp[1][T]);
	}
	return 0;
}
