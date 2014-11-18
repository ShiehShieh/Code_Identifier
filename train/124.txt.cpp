#include<stdio.h>
#include<limits>
#include<iostream>
int n,date[1001],dp[1001][12001],sum;
const int k=6000,amax=INT_MAX;
void init()
{
     int i,j,a,b;
     scanf("%d",&n);
     sum=0;
     for(i=1;i<=n;i++)
     {
      scanf("%d %d",&a,&b);
      date[i]=a-b;
      sum+=abs(a-b);
     }     
     for(i=1;i<=n;i++)for(j=-sum;j<=sum;j++)dp[i][k+j]=amax;
 }
 int min(int a,int b)
 {
     if(a<b)return a;
     return b;
 }
int main()
{
   int i,j; 
  init();
   dp[1][k+date[1]]=0;dp[1][k-date[1]]=1;
   for(i=2;i<=n;i++)
   {
    for(j=-sum;j<=sum;j++)
     {
    if(dp[i-1][k+j-date[i]]!=amax)dp[i][k+j]=min(dp[i][k+j],dp[i-1][k+j-date[i]]);
    if(dp[i-1][k+j+date[i]]!=amax)dp[i][k+j]=min(dp[i][k+j],dp[i-1][k+j+date[i]]+1);
    }
   }
   for(i=0;i<=sum;i++)
   if(dp[n][i+k]!=amax||dp[n][k-i]!=amax)break;
   if(dp[n][i+k]<dp[n][k-i])printf("%d",dp[n][k+i]);
   else printf("%d",dp[n][k-i]);
   return 0;
}


