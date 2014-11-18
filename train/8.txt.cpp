#include<iostream>
#include<cmath>
#include<stdio.h> 
using namespace std;
bool edge[1001][1001],b[1001];
double t,point[1001][2],peo[1001][3];
int a,r,ver[1001];
void init()
{
     int i,j,k;
     double x,y,z;
     cin>>r>>a>>t;
     for(i=1;i<=r;i++)for(j=1;j<=a;j++)edge[i][j]=false;
     for(i=1;i<=a;i++)ver[i]=-1;
     for(i=1;i<=a;i++)cin>>point[i][0]>>point[i][1];
     for(i=1;i<=r;i++)cin>>peo[i][0]>>peo[i][1]>>peo[i][2];
     for(i=1;i<=r;i++)
      for(j=1;j<=a;j++)
      if(t*peo[i][2]>=(sqrt((point[j][0]-peo[i][0])*(point[j][0]-peo[i][0])+(point[j][1]-peo[i][1])*(point[j][1]-peo[i][1]))))
      edge[i][j]=true; 
}
bool talk(int x)
{
  int i,j;
  
  for(i=1;i<=a;i++)
  if(edge[x][i]==true&&b[i])
  {
   b[i]=false;
   if(ver[i]==-1){ver[i]=x;return true;}
   else if(talk(ver[i])==true)
         {ver[i]=x;return true;}
  }
  return false;
}
int main()
{
    int i,j,k,sum;
    init();
    sum=0;
    for(i=1;i<=r;i++)
    {
     for(j=1;j<=a;j++)
    if(edge[i][j]==true)
     {
      if(ver[j]==-1){ver[j]=i;sum++;break;}
      else{ 
           for(k=1;k<=a;k++)b[k]=true; 
           if(talk(ver[j])==true)
           {
             ver[j]=i;                   
             sum++;break;       
           }
          }      
     } 
  }
    cout<<sum;
    return 0;
}

