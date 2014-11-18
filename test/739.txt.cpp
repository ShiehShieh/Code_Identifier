#include<iostream>
using namespace std;
int n,m,point,maxx=21;
char map[21][21];
int dp[401][401];
bool ifness[21][21];
bool check(int x,int y)
{
  if(x>=1&&x<=n&&y>=1&&y<=m&&ifness[x][y])return true;
  return false;
}
void dfs(int x,int y,char z)
{
      ifness[x][y]=false;                 
  if(map[x][y]==z){
                   dp[point][(x-1)*m+y]=0;
                   if(check(x-1,y))dfs(x-1,y,z);                 
                   if(check(x+1,y))dfs(x+1,y,z);
                   if(check(x,y-1))dfs(x,y-1,z);
                   if(check(x,y+1))dfs(x,y+1,z);
                   }
  else dp[point][(x-1)*m+y]=1;  
}
void init()
{
  int i,j,k,p;
  cin>>n>>m;
  for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>map[i][j];
  for(i=1;i<=n*m;i++)for(j=1;j<=n*m;j++)dp[i][j]=maxx;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
       for(k=1;k<=n;k++)for(p=1;p<=m;p++)ifness[k][p]=true;
      point=(i-1)*m+j;
      dfs(i,j,map[i][j]);  
    }
}
void floyd()
{
  int i,j,k,minex;
  for(k=1;k<=m*n;k++)
   for(i=1;i<=m*n;i++)
    for(j=1;j<=m*n;j++)
    if(dp[i][k]!=maxx&&dp[k][j]!=maxx&&dp[i][j]>dp[i][k]+dp[k][j])
    dp[i][j]=dp[i][k]+dp[k][j];     
  minex=maxx;
  for(i=1;i<=m;i++)
  {
    for(j=m*n;j>(n-1)*m;j--)
    if(dp[i][j]<minex)minex=dp[i][j]; 
  }
  cout<<minex+1; 
}
int main()
{
    init();
    floyd();
    return 0;
}

