#include <iostream>
using namespace std;
int main(){
  long long dp[100];
  int n,m,i;
  cin>>n>>m;
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  for(i=1;i<=n;i++){
    if(i<m)
      dp[i]=dp[i-1]+dp[i-1];
    if(i==m)
      dp[i]=dp[i-1]+dp[i-1]-1;
    if(i>m)
      dp[i]=dp[i-1]+dp[i-1]-dp[i-m-1];
  }
  cout<<dp[n]<<endl;
  return 0;
}
