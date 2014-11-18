#include<iostream>
using namespace std;
int n,m,sum[301],p[301][301],best;
bool visit[301],map[301][301],flag[301][301],temp[301];
void init()
{
     int i,x,y;
     cin>>n>>m;
     for (i=1;i<=m;i++)
     {
        cin>>x>>y;
        map[x][y]=map[y][x]=1;
     }
     best=n+1;
} 
void build(int root)
{
     visit[root]=1;
     int i;
     for (i=1;i<=n;i++)
     {
         if ( map[root][i]==1 && visit[i]==0 )
         {
              sum[root]++;
              p[root][sum[root]]=i;
              build(i);
         }
     }
     visit[root]=0;
}
void dfs(int deep,int sick)
{
     int i,j,c=0;
     if ( sick>best ) return;
         for (i=1;i<=n;i++)
          flag[deep+1][i]=0;
         for (i=1;i<=n;i++)
         {
          if ( flag[deep][i]==1 )
          {
               c+=sum[i];
               for (j=1;j<=sum[i];j++)
                flag[deep+1][p[i][j]]=1;
          }
         }
         if ( c==0 )
              best=sick;
         else
         {
             for (i=1;i<=n;i++)
             {
                 if ( flag[deep+1][i]==1 )
                 {
                      flag[deep+1][i]=0;
                      dfs(deep+1,sick+c-1);
                      flag[deep+1][i]=1;
                 }
             }
         }

}
main()
{
      init();
      build(1);
      flag[1][1]=1;
      dfs(1,1);
      cout<<best;
}

