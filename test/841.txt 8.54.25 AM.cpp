#include<iostream>
#define MAXNUM 100
int dp[MAXNUM][MAXNUM]={};
int main(){
	int n;
	scanf("%d",&n);
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)
			dp[i][j]=dp[i][j-1]*(j>0)+dp[i-1][j]*(i>j);
	printf("%d\n",dp[n][n]);
   return 0;
}
