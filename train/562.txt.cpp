#include<stdio.h>
#include<iostream>
#include<limits>
int date[1501],dp[1501][3],n,root;
int sons[1501][1500]={0};
int amin(int a,int b)
{
    if(a<b)return a;
    return b;
}
void init()
{
     int i,j,a,b,m;
     bool ifness[1501];
     scanf("%d",&n);   
     for(i=1;i<=n;i++)ifness[i]=true;  
     for(i=1;i<=n;i++)
     {
      scanf("%d %d %d",&a,&b,&m);
      date[a]=b;sons[a][0]=m;
      for(j=1;j<=m;j++){
                        scanf("%d",&sons[a][j]);
                        ifness[sons[a][j]]=false;
                        }
     }
     for(i=1;i<=n;i++)
     if(ifness[i]){root=i;break;}
 }
void dfs(int num)
{
  int i,j,minex; 
  if(sons[num][0]==0){
                      dp[num][0]=date[num];
                      dp[num][1]=INT_MAX;
                      dp[num][2]=0;
                      return ;
                      }
                                          
  for(i=1;i<=sons[num][0];i++)dfs(sons[num][i]);
 
  for(i=1;i<=sons[num][0];i++){ 
                               if(dp[sons[num][i]][1]==INT_MAX)break;
                               else dp[num][2]+=dp[sons[num][i]][1]; 
                              }
  if(i<=sons[num][0])dp[num][2]=INT_MAX;
 
  for(i=1;i<=sons[num][0];i++)dp[num][0]+=amin(dp[sons[num][i]][0],amin(dp[sons[num][i]][2],dp[sons[num][i]][1]));
  dp[num][0]+=date[num];
  
  minex=INT_MAX;
  for(i=1;i<=sons[num][0];i++)
  dp[num][1]+=amin(dp[sons[num][i]][0],dp[sons[num][i]][1]);
  minex=INT_MAX;
  for(i=1;i<=sons[num][0];i++)
  {
  if(dp[sons[num][i]][0]<dp[sons[num][i]][1])minex=0;          
  if(dp[sons[num][i]][0]>=dp[sons[num][i]][1])
     if(dp[sons[num][i]][0]-dp[sons[num][i]][1]<minex)minex=dp[sons[num][i]][0]-dp[sons[num][i]][1];
  }
  if(minex==INT_MAX)dp[num][1]=INT_MAX;
  else dp[num][1]+=minex;
}
int main()
{
     init();
    dfs(root);
    printf("%d",amin(dp[root][0],dp[root][1]));
    return 0;
}
