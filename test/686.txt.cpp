#include<stdio.h>
#include<limits>
#include<iostream>
using namespace std;
int n,m,s,goal;
int edge[100001][3],map[1001][1001],cost[1001][1001];
bool sign,ifness[1001];
void init()
{
     int i,j;
     scanf("%d %d %d",&n,&m,&s);
      for(i=1;i<=n;i++){
                       map[i][0]=0;
                       for(j=1;j<=n;j++)map[i][j]=INT_MAX;
                       }
     for(i=1;i<=m;i++){
                       scanf("%d %d %ld",&edge[i][0],&edge[i][1],&edge[i][2]);
                       map[edge[i][0]][0]++;
                       map[edge[i][0]][map[edge[i][0]][0]]=edge[i][1];
                       cost[edge[i][0]][map[edge[i][0]][0]]=edge[i][2];
                       }
}
void dfs(int num,long sum)
{
  int i;
  if(num==goal&&ifness[num]==false)
                                   {
                                    if(sum<0)sign=false;
                                    return ;
                                    }
    ifness[num]=false;
  for(i=1;i<=map[num][0];i++)
  if((ifness[map[num][i]]||map[num][i]==goal)&&sign)dfs(map[num][i],sum+cost[num][i]);
}
int main()
{
    int i,j;
    long d[1001];
    bool w;
     init();
    for(i=1;i<=n;i++)d[i]=LONG_MAX;
    d[s]=0;    sign=true;
    for(i=1;i<n;i++)
    {
     w=true;
     for(j=1;j<=m;j++)
     if(d[edge[j][0]]!=LONG_MAX&&d[edge[j][1]]>d[edge[j][0]]+edge[j][2])
     {d[edge[j][1]]=d[edge[j][0]]+edge[j][2];w=false;}
     if(w)break;
     if(d[s]<0){sign=false;break;}
     }   
     if(!sign){printf("-1");return 0;}  
     for(i=1;i<=n;i++)
      if(d[i]==LONG_MAX)
      { 
       for(j=1;j<=n;j++)ifness[j]=true;
       goal=i;
       dfs(i,0);
       if(!sign){printf("-1");return 0;}
      }
     for(i=1;i<=n;i++)
     if(d[i]==LONG_MAX)printf("NoPath\n");
     else printf("%ld\n",d[i]);
    return 0;
}

