#include<stdio.h>
#include<math.h>
#include<limits>
#include<iostream>
int amax(int a,int b)
{
 if(a>b)return a;
 return b;
} 
int amin(int a,int b)
{
    if(a<b)return a;
    return b;
}
int main()
{
  int n,date[11],dp[11][11][2],s[11],i,j,k; 
  scanf("%d",&n);
  for(i=1;i<=n;i++)for(j=1;j<=n;j++){dp[i][j][0]=INT_MIN;dp[i][j][1]=INT_MAX;}
  for(i=1;i<=n;i++){
                    scanf("%d",&date[i]);
                    dp[i][i][0]=dp[i][i][1]=abs(date[i]);
                    if(date[i]<0)s[i]=-1;
                    else s[i]=1;
                    }
  for(j=1;j<n;j++)
  for(i=1;i<=n-j;i++)
   for(k=0;k<j;k++)
   {
   dp[i][i+j][0]=amax(dp[i][i+j][0],amax(dp[i][i+k][0]+s[i+k+1]*dp[i+k+1][i+j][0],dp[i][i+k][0]+s[i+k+1]*dp[i+k+1][i+j][1])); 
   dp[i][i+j][1]=amin(dp[i][i+j][1],amin(dp[i][i+k][1]+s[i+k+1]*dp[i+k+1][i+j][1],dp[i][i+k][1]+s[i+k+1]*dp[i+k+1][i+j][0]));
   }printf("%d",dp[1][n][0]);
  return 0;
}

