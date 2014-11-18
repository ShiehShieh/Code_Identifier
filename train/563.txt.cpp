#include<iostream>
#include<math.h>
#define check(a) ins[a]?++x:++y
using namespace std;
int n,m,i,j,k,x,y,dp[2501];
char word;
bool ins[2501],map[2501][2501];
int main(){
    cin>>n>>m;
    for(i=1;i<=n;i++){
          cin>>word;
          ins[i]=(word=='H');
          }
    for(i=1;i<=n;i++){
          x=y=0;
          for(j=i;j<=n;j++){
                check(j);
                if(abs(x-y)<=m||x==0||y==0) map[i][j]=true;
                else                       map[i][j]=false;
                }
          }
    dp[0]=0;
    for(i=1;i<=n;i++){
          dp[i]=10000000;
          for(j=1;j<=i;j++)
                if(map[j][i]) dp[i]=min(dp[j-1]+1,dp[i]);
          }
    cout<<dp[n]<<endl;
    return 0;
}

