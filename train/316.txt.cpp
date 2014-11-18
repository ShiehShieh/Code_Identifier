#include<iostream>
using namespace std;
struct
{int mv,mp; 
 int f1v,f2v,f1p,f2p;
}thing[61];
int dp[61][32001];
int main()
{int money,n,i,j,v,p,q;
 cin>>money>>n;
 for(i=1;i<=n;i++)
   {thing[i].mv=0;
    thing[i].mp=0;
    thing[i].f1v=0;
    thing[i].f2v=0;
    thing[i].f1p=0;
    thing[i].f2p=0;
   }
 for(i=1;i<=n;i++)
   {cin>>v>>p>>q;
    if(q==0)
       {thing[i].mv=v;
        thing[i].mp=p;
       }
    else
      {if(thing[q].f1p==0)
         {thing[q].f1v=v;
          thing[q].f1p=p;
         }
       else
         {thing[q].f2v=v;
          thing[q].f2p=p;
         }
      }
   }
 for(i=1;i<=n;i++)
   for(j=1;j<=money;j++)
     {dp[i][j]=dp[i-1][j];
      if(j>=thing[i].mv)
        dp[i][j]=max(dp[i][j],dp[i-1][j-thing[i].mv]+thing[i].mv*thing[i].mp);
      if(j>=thing[i].mv+thing[i].f1v)
        dp[i][j]=max(dp[i][j],dp[i-1][j-thing[i].mv-thing[i].f1v]+thing[i].mv*thing[i].mp+thing[i].f1v*thing[i].f1p);
      if(j>=thing[i].mv+thing[i].f2v)
        dp[i][j]=max(dp[i][j],dp[i-1][j-thing[i].mv-thing[i].f2v]+thing[i].mv*thing[i].mp+thing[i].f2v*thing[i].f2p);
      if(j>=thing[i].mv+thing[i].f1v+thing[i].f2v)
        dp[i][j]=max(dp[i][j],dp[i-1][j-thing[i].mv-thing[i].f1v-thing[i].f2v]+thing[i].mv*thing[i].mp+thing[i].f1v*thing[i].f1p+thing[i].f2v*thing[i].f2p);
     }  
 cout<<dp[n][money]<<endl;
 return 0;
}


