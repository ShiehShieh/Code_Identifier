#include<iostream>
using namespace std;
long long a,b,best,ans[100001],mark,limt,way[100001];
void dfs(long long x,long long y,long long deep)
{
     long long l1,l2,i,xx,yy,j;
     l1=max(way[deep-1]+1,y/x);
     l2=min(y*(limt-deep+1)/x,best-1);
     for (i=l1;i<=l2;i++)
     {
         xx=x;yy=y;
         way[deep]=i;
         xx=xx*i-yy;
         if (x<0)continue;
         yy=yy*i;
         if ( deep<limt )dfs(xx,yy,deep+1);
         if ( i<best && xx==0 )
         {
              mark=1;best=i;
              for (j=1;j<=limt;j++)
              ans[j]=way[j];
         }
     }
}
void work()
{
     long long i;
     mark=0;
     way[0]=1;
     best=99999999;
     while (mark==0)
     {
           limt++;
           dfs(a,b,1);
     }
     for (i=1;i<=limt;i++)
     cout<<ans[i]<<" ";
}
int main()
{
    cin>>a>>b;
    work();
}
      
