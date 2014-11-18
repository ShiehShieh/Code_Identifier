#include <iostream>
#define MAX 20002
using namespace std;
int dp[32][MAX],data[32];
int GetMin(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
} 
int GetMax(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int n,i,j,v;
	while(scanf("%d",&v)!=EOF)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&data[i]);
		for(i=0;i<=v;i++)
		{
			if(i>=data[1])
				dp[1][i]=data[1];
			else
				dp[1][i]=0;
		}
		for(i=2;i<=n;i++)
			for(j=1;j<=v;j++)
			{
				if(j>=data[i])
					dp[i][j]=GetMax(dp[i-1][j],dp[i-1][j-data[i]]+data[i]);
				else
					dp[i][j]=dp[i-1][j];
			}
		printf("%d\n",v-dp[n][v]);
	}
	return 0;
}
