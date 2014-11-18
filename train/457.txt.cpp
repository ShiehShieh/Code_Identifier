#include<iostream>
#include<limits>
using namespace std;
long m,n,date[2001][2001],dp[2001][2002],maxex;
 long maxx(long a,long b,long c)
{
    if(b>a)a=b;
    if(c>a)a=c;
    return a;
}
int main()
{
 long i,j;
 cin>>m>>n;
 for(i=1;i<=m;i++)for(j=1;j<=n;j++)cin>>date[i][j];
 for(i=1;i<=m;i++)
 for(j=0;j<=n+1;j++)dp[i][j]=LONG_MIN;
  dp[m][n/2+1]=date[m][n/2+1];
  dp[m][n/2]=date[m][n/2];
  dp[m][n/2+2]=date[m][n/2+2];
  for(i=m-1;i>=1;i--)
  for(j=1;j<=n;j++)
  {
   if(dp[i+1][j-1]!=LONG_MIN)dp[i][j]=dp[i+1][j-1]+date[i][j];
   if(dp[i+1][j]!=LONG_MIN)dp[i][j]=max(dp[i][j],dp[i+1][j]+date[i][j]);
   if(dp[i+1][j+1]!=LONG_MIN)dp[i][j]=max(dp[i][j],dp[i+1][j+1]+date[i][j]);
  }
  maxex=dp[1][1];
 for(j=2;j<=n;j++)
 if(dp[1][j]>maxex)maxex=dp[1][j];
 cout<<maxex;
 return 0;   
}

