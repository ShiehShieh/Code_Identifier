/*  Vijos P1180  */

#include <iostream>
using namespace std;

int n,m;
int w[302];
int fa[302];

int lc[302],rc[302];
int f[302][302];

void build(int x)
{
     int i,tmp;
     
     for (i=1;i<=n;i++)
       if (fa[i]==x)
         break;
     
     if (i<=n)
       {
          lc[x]=i;
          tmp=i;
          for (i++;i<=n;i++)
            {
              if (fa[i]==x)
                {
                   rc[tmp]=i;
                   tmp=i;
                }
            }
          for (i=1;i<=n;i++)
            if (fa[i]==x)
              build(i);
       }
}

void init()
{
     cin>>n>>m;
     for (int i=1;i<=n;i++)
       cin>>fa[i]>>w[i];
     for (int i=0;i<=n;i++)
       lc[i]=rc[i]=-1;
     for (int i=0;i<=n;i++)
       for (int j=0;j<=n;j++)
         f[i][j]=(-1);
     build(0);
}
int dfs(int x,int y)
{
    int ans=0;
    if (f[x][y]!=(-1))
      return f[x][y];
    if (y==0 ||( lc[x]==(-1) && rc[x]==(-1)))
      {
         if (y>=1)
           return w[x];
         else 
           return 0;
      }
    else
      {
        if (lc[x]==(-1) && rc[x]!=(-1))
          {
             ans=max( ans , dfs(rc[x],y-1)+w[x] );
             ans=max( ans , dfs(rc[x],y) );
          }
        if (lc[x]!=(-1) && rc[x]==(-1))
          ans=max( ans , dfs(lc[x],y-1)+w[x] );
        if (lc[x]!=(-1) && rc[x]!=(-1))
          {
             ans=max( ans , dfs(rc[x],y) );
             for (int i=0;i<y;i++)
               ans=max( ans , dfs(lc[x],i)+dfs(rc[x],y-i-1)+w[x] );
          }
        f[x][y]=ans;
        return ans;
    }
}

int main(void)
{
      init();
      cout<<dfs(0,m+1)<<endl;
      return 0;
}
