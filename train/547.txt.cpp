#include<iostream>
using namespace std;
int n,m,t;
int map[500][500];
int main()
{
    cin>>n>>m>>t;
    int a;
    for(int i=1;i<=n;i++)
      {
            cin>>a;
            map[m][i]=a;
      }
    for(int i=m+1;i<=n;i++)
      for(int j=1;j<=n;j++)
       {
              if(j==1)map[i][j]=map[i-1][n];
              else map[i][j]=map[i-1][j-1];
       }
    for(int i=m-1;i>=1;i--)
      for(int j=1;j<=n;j++)
       {
              if(j==n)map[i][j]=map[i+1][1];
              else map[i][j]=map[i+1][j+1];
       }
    for(int i=1;i<=n;i++)
      cout<<map[i][t]<<" ";
}

