#include<iostream>
#include<limits>
using namespace std;
struct std
{
int lc,rc,w,d;
}tr[101];
int sum[101][101],map[101][101][101];
int n,k;
void did(int son,int father)
{
 int i;
 for(i=0;i<=n;i++)
 if(sum[father][i]!=-1)
 sum[son][i]=sum[father][i]+tr[son].d;
 if(tr[son].lc!=-1)
 did(tr[son].lc,son);
 if(tr[son].rc!=-1)
 did(tr[son].rc,father);     
}
void init()
{
     int i,j,p,a;
     cin>>n>>k;
     for(i=0;i<=n;i++)for(j=0;j<=n;j++)sum[i][j]=-1;
     for(i=0;i<=n;i++)for(j=0;j<=n;j++)for(p=0;p<=n;p++)map[i][j][p]=-1;
       for(i=0;i<=n;i++){tr[i].lc=tr[i].rc=-1;sum[i][i]=0;}
     for(i=1;i<=n;i++)
     {
      cin>>tr[i].w>>a>>tr[i].d;
      tr[i].rc=tr[a].lc;
      tr[a].lc=i;
     }
     sum[0][0]=0;
     did(tr[0].lc,0);
 }
 int work(int from,int to)
 {
     return tr[from].w*sum[from][to];
 }
int dfs(int from,int to,int i)
{
  int j,ans;
  if(from==-1||to==-1)return 0;
  if(map[from][to][i]!=-1)return map[from][to][i];
  ans=INT_MAX;
  for(j=0;j<i;j++)
  {
   ans=min(dfs(tr[from].lc,from,j)+dfs(tr[from].rc,to,i-j-1),ans);   
  }
  for(j=0;j<=i;j++)
 {
  ans=min(dfs(tr[from].lc,to,j)+dfs(tr[from].rc,to,i-j)+work(from,to),ans);                  
 } 
  map[from][to][i]=ans;
  return map[from][to][i];
}
int main()
{
    init();
    cout<<dfs(tr[0].lc,0,k);
    return 0;   
}

