#include<stdio.h>
#include<iostream>
#include<limits>
int amax=INT_MAX;
int n,m;
int map[201][201]={0},f[201][201];
void init()
{
     int i,j,a,b,c;
     scanf("%d %d",&n,&m);    
     for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=amax;
     for(i=1;i<=n;i++)scanf("%d",&f[i][i]);     
     for(i=1;i<=m;i++)
     {
      scanf("%d %d %d",&a,&b,&c);
      if(map[a][b]==0)
      {
      map[a][b]=c;
      f[a][b]=c+f[a][a]+f[b][b];
      }
      else 
        if(map[a][b]>c)
           {
           map[a][b]=c;
           f[a][b]=c+f[a][a]+f[b][b];
           }
     }
 }
void floyd()
{
  int i,j,k;
  for(k=1;k<=n;k++)
   for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     if(f[i][k]!=amax&&f[k][j]!=amax)
     if(f[i][k]+f[k][j]-f[k][k]<f[i][j])
     f[i][j]=f[i][k]+f[k][j]-f[k][k];
}
void outside()
{
 int i,j;
 j=amax;
 for(i=2;i<=n;i++)
  if(map[i][1])
   if(map[i][1]+f[1][i]<j){j=map[i][1]+f[1][i];}
   if(j==amax)printf("-1");
   else printf("%d",j);
}
int main()
{
 init();
 floyd();
 outside();
 return 0;
}

