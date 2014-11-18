#include<stdio.h>
#include<limits>
#include<iostream>
int amax=INT_MAX;
int n,date[1001][1001],dp[1001][1001]={0};
int min(int a,int b)
{
    if(a<b)return a;
    return b;
}
int main()
{
  int i,j,k;
 scanf("%d",&n);
 for(i=1;i<=n;i++)for(j=1;j<=i;j++) scanf("%d",&date[i][j]);
 for(i=0;i<=n+1;i++)for(j=0;j<=n+1;j++)dp[i][j]=amax;
 
 i=n;
  dp[n][1]=date[n][1];
  for(j=2;j<=n;j++)
  if(dp[i][j-1]+date[i][j]<dp[i][j])dp[i][j]=dp[i][j-1]+date[i][j];
  for(j=n-1;j>=1;j--)
  if(dp[i][j+1]+date[i][j]<dp[i][j])dp[i][j]=dp[i][j+1]+date[i][j];
  dp[i][1]=min(dp[i][1],dp[i][i]+date[i][1]);dp[i][i]=min(dp[i][i],dp[i][1]+date[i][i]);

  
 for(i=n-1;i>=1;i--)
 {  
                    
 for(j=1;j<=i;j++)dp[i][j]=min(dp[i][j],min(dp[i+1][j],dp[i+1][j+1]))+date[i][j];
 dp[i][1]=min(dp[i][1],dp[i+1][i+1]+date[i][1]);dp[i][i]=min(dp[i][i],dp[i+1][1]+date[i][i]);
  for(j=2;j<i;j++)
  if(dp[i][j-1]+date[i][j]<dp[i][j])dp[i][j]=dp[i][j-1]+date[i][j];
  dp[i][1]=min(dp[i][1],dp[i][i]+date[i][1]);dp[i][i]=min(dp[i][i],dp[i][1]+date[i][i]);
  for(j=i-1;j>1;j--)
  if(dp[i][j+1]+date[i][j]<dp[i][j])dp[i][j]=dp[i][j+1]+date[i][j];
  dp[i][1]=min(dp[i][1],dp[i][i]+date[i][1]);dp[i][i]=min(dp[i][i],dp[i][1]+date[i][i]);
  for(j=2;j<i;j++)
  dp[i][j]=min(dp[i][j],min(min(min(dp[i+1][j],dp[i+1][j+1]),dp[i][j-1]),dp[i][j+1])+date[i][j]);
  dp[i][1]=min(dp[i][1],min(min(min(min(dp[i+1][1],dp[i+1][2]),dp[i+1][i+1]),dp[i][2]),dp[i][i])+date[i][1]);
  dp[i][i]=min(dp[i][i],min(min(min(min(dp[i+1][i],dp[i+1][i+1]),dp[i+1][1]),dp[i][i-1]),dp[i][1])+date[i][i]);
}
 printf("%d",dp[1][1]);
 return 0;
}

