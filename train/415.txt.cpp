#include <iostream>
using namespace std;

int n,m;
int w[101],v[101],d[101];
int lc[101],rc[101],f[101][101][51];

void build(int root)
{
     int tmp;
     int i;
     for (i=1;i<=n;i++)
       if (v[i]==root)
        break;
     
     if (i<=n)
       {
          lc[root]=i;
          tmp=i;
          for (i++;i<=n;i++)
            {
               if (v[i]==root)
                {
                    rc[tmp]=i;
                    tmp=i;
                }
            }
          
          for (i=1;i<=n;i++)
            if (v[i]==root)
              {
                 d[i]+=d[root];
                 build(i);
              }
       }
}

void init()
{
     cin>>n>>m;
     for (int i=1;i<=n;i++)
       scanf("%d%d%d",&w[i],&v[i],&d[i]);
     
     memset(lc,-1,sizeof(lc));
     memset(rc,-1,sizeof(rc));
     memset(f,-1,sizeof(f));
     
     build(0);
}

int dfs(int x,int from,int to)
{
    int ans,tmin,tmp;
    
    if (f[x][from][to]!=(-1))
      return(f[x][from][to]);
    
    if (lc[x]==(-1) && rc[x]==(-1))
      {
         if (to>=1)
           return 0;
         else
           return( w[x]*(d[x]-d[from]) );
      }
    else
      {
         tmin=w[x]*(d[x]-d[from]);
         if ( lc[x]!=-1 && rc[x]==-1)
           tmin+=dfs(lc[x],from,to);
         if ( rc[x]!=-1 && lc[x]==-1 )
           tmin+=dfs(rc[x],from,to);
         if ( lc[x]!=-1 && rc[x]!=-1 )
           {
              tmp=INT_MAX;
              for (int i=0;i<=to;i++)
                if ( tmp>dfs(lc[x],from,i)+dfs(rc[x],from,to-i) )
                  tmp=dfs(lc[x],from,i)+dfs(rc[x],from,to-i);
              tmin+=tmp;
           }
        
        ans=tmin;
        
        if (to>=1)
          {
             tmin=0;
             if (lc[x]!=(-1) && rc[x]==(-1))
                tmin+=dfs(lc[x],x,to-1);
             
             if (lc[x]==(-1) && rc[x]!=(-1))
                tmin+=dfs(rc[x],from,to-1);
             
             if (lc[x]!=(-1) && rc[x]!=(-1))
                {
                   tmin=(INT_MAX);
                   for (int i=0;i<=to-1;i++)
                     tmin=min(tmin,dfs(lc[x],x,i)+dfs(rc[x],from,to-1-i));
                }
             ans=min(ans,tmin);
          }
        
        f[x][from][to]=ans;
        return ans;
    }
}

int main(void)
{
      init();
      cout<<dfs(0,0,m)<<endl;
      return 0;
}
