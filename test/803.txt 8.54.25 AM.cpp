#include<iostream>
#define MAXNUM 21
long long dp[MAXNUM][MAXNUM]={};
int main(){
	int n,m,sn,sm;
	dp[0][0]=1;
	scanf("%d%d%d%d",&n,&m,&sn,&sm),sn,sm;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			if(abs((sn-i)*(sm-j))==2||(i==sn&&j==sm))
				dp[i][j]=0;
			else if(i!=0||j!=0)
				dp[i][j]=dp[i][j-1]*(j>0)+dp[i-1][j]*(i>0);
	printf("%I64d\n",dp[n][m]);
   return 0;
}
