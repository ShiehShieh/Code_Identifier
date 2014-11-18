#include<iostream>
using namespace std;
int n,m;
int map[1001][1001];
int map1[1001][1001];
int min(int a,int b,int c)
{
    int minn=a;
    if(b<minn)minn=b;
    if(c<minn)minn=c;
    return minn;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        {cin>>map[i][j];map1[i][j]=map[i][j];}
        
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(map[i][j])
        {
             map1[i][j]=min(map1[i-1][j],map1[i][j-1],map1[i-1][j-1])+1;                 
        }
    int sum=0;     
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(map1[i][j]>sum)sum=map1[i][j];   
    cout<<sum;
}

