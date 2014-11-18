#include<iostream>
#define MAXNUM 50
long long dp[MAXNUM][2]={};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	dp[0][0]=1;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j)
			dp[(j+1)%n][~i&1]+=dp[j][i&1],
			dp[(j+n-1)%n][~i&1]+=dp[j][i&1],dp[j][i&1]=0;
	}
	printf("%I64d\n",dp[0][m&1]);
   return 0;
}
