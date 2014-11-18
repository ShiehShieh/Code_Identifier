#include<iostream>
#include<limits>
using namespace std;
long dp[10001],date[10001],n,l1,l2,l3,c1,c2,c3,a,b;
void init()
{
     int i;
     cin>>l1>>l2>>l3>>c1>>c2>>c3>>n>>a>>b;
     for(i=2;i<=n;i++)cin>>date[i];
     for(i=a+1;i<=b;i++)dp[i]=LONG_MAX;
     dp[a]=0;
 }
 long minex(long a,long b)
 {
      if(a<b)return a;
      return b;
  }
int main()
{
    int i,j,k;
    init();
    for(i=a+1;i<=b;i++)
    {
     j=i-1;
     while(date[i]-date[j]<=l3&&j>=a)
     {
      if(date[i]-date[j]<=l1)dp[i]=minex(dp[i],dp[j]+c1);
      else if(date[i]-date[j]<=l2)dp[i]=minex(dp[i],dp[j]+c2);
      else dp[i]=minex(dp[i],dp[j]+c3);
      j--;
     }
    }
    cout<<dp[b];
    return 0;
}
