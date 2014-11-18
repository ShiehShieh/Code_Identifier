#include<iostream>
#define MAXNUM 1010
long long dp[MAXNUM]={0,1};
int main(){
	int n=MAXNUM;
	for(int i=2;i<n;++i){
		++dp[i];
		for(int j=1;j<=i/2;++j)
			dp[i]+=dp[j];
	}
	scanf("%d",&n);
	printf("%d\n",dp[n]);
   return 0;
}

