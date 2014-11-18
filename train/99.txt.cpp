#include<stdio.h>
#include<iostream>
#include<limits>
int amax=INT_MAX;
int n,m;
int map[201][201],f[201][201];
int minex(int a,int b)
{
    if(a<b)return a;
    return b;
}
void init()
{
     int i,j,a,b,c;
     for(i=1;i<=n;i++)for(j=1;j<=n;j++){map[i][j]=0;f[i][j]=amax;}
     for(i=1;i<=m;i++)
     {
      scanf("%d %d %d",&a,&b,&c);
      map[a][b]=map[b][a]=f[b][a]=f[a][b]=c;
     }
 }
void floyd()
{
  int i,j,k,ans;
  ans=amax;
  for(k=1;k<=n;k++)
  {
   for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    if(map[i][k]&&map[k][j]&&f[i][j]!=amax)
     ans=minex(ans,f[i][j]+map[i][k]+map[k][j]);
    for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     if(f[i][k]!=amax&&f[k][j]!=amax&&f[i][k]+f[k][j]<f[i][j])
     f[i][j]=f[i][k]+f[k][j];
  }
  if(ans==amax)printf("No solution.\n");
  else printf("%d\n",ans);
}
int main()
{
 while(scanf("%d %d",&n,&m)!=EOF)
 {   
 init();
 floyd();
 }
 return 0;
}
