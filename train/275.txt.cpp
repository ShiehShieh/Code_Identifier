#include<stdio.h>
int n,m,y[101],map[101][101]={0};
bool b[101];
bool check(int x)
{
     int i;
     for(i=1;i<=m;i++)
     if(b[i]&&map[x][i])
     {
      b[i]=false;
      if(y[i]==-1||check(y[i]))
        {
          y[i]=x;
          return true;         
        }
     }
     return false;
 }
int main()
{
  int i,j,sum;
  char t;
  scanf("%d %d\n",&n,&m);
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=m;j++)
   {
   scanf("%c",&t);
   if(t=='1')map[i][j]=1;
   }
   scanf("\n");
  }
  for(j=1;j<=m;j++)y[j]=-1;
  sum=0;
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=m;j++)b[j]=true;
   for(j=1;j<=m;j++)
   if(b[j]&&map[i][j])
   {
    b[j]=false;
      if(y[j]==-1||check(y[j]))
       {
         y[j]=i;
         sum++;
         break;
       }
   }
  }
  printf("%d",sum);
  return 0;
}
