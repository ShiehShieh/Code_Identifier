#include <iostream>
using namespace std;
int dp[500][500],l;
int main()
{   int maxn=0;
    cin>>l;
    for(int i=1;i<=l;i++)
       for(int j=1;j<=(l-i)*2+1;j++)
          {char ch;
           cin>>ch;
           if(ch=='-')dp[i][j]=1;
           else       dp[i][j]=0; 
          }
   for(int i=2;i<=l;i++)
      for(int j=1;j<=2*(l-i)+1;j++)
         if(j%2==1&&dp[i-1][j+1]>=1&&dp[i][j]==1)
           {dp[i][j]=min(dp[i-1][j],dp[i-1][j+2])+1;
            maxn>?=dp[i][j];
           }
   if(maxn>0)cout<<maxn*maxn;
   else      cout<<1;
}
