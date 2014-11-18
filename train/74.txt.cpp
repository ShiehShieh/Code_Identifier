#include<stdio.h>
#include<iostream> 
int n;
int least[2001],map[2001][2001]={0},ans[2001];
bool ifness[2001];
void init()
{
     int i,a,b,r;
     scanf("%d",&n);
     for(i=1;i<=n;i++)least[i]=0;
     scanf("%d%d%d",&a,&b,&r);
     while(!(a==0&&b==0&&r==0))
     {
      map[a][b]=r;
      scanf("%d%d%d",&a,&b,&r); 
     }
     for(i=2;i<=n;i++)
     if(map[1][i])least[i]=map[1][i];
 }
 int select()
 {
     int i,maxex,ws;
     maxex=0;
     for(i=2;i<=n;i++)
     if(least[i]>maxex&&ifness[i]){maxex=least[i];ws=i;}
     return ws;
 }
 void work()
 {
  int i,j,k;
  for(i=2;i<=n;i++)ifness[i]=true;
  for(i=2;i<=n;i++)
  {
   j=select();
   ans[j]=least[j];
   ifness[j]=false;
   for(k=1;k<=n;k++)
   if(ifness[k]==true)
   if(map[j][k]>least[k]&&least[j]>least[k])
   {
     if(map[j][k]<least[j])least[k]=map[j][k];
     else least[k]=least[j];
   }
  }
 }
 void outside()
 {
      int i;
      for(i=2;i<=n;i++)printf("%d\n",ans[i]);
  }
int main()
{
    init();
    work();
    outside();
    return 0;
}

