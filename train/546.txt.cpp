#include<iostream>
using namespace std;
int f[1100][1100];
int a[1100][1100];
int n,m;
long int maxn;
int min(int a,int b,int c)
{
    if(a<=b&&a<=c)return a;
    if(b<=a&&b<=c)return b;
    else return c;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>a[i][j];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      {
        if(a[i][j])
        {
        if(a[i-1][j]&&a[i][j-1]&&a[i-1][j-1])
         f[i][j]=min(f[i-1][j],f[i][j-1],f[i-1][j-1])+1;
        else f[i][j]=1;
        if(maxn<f[i][j])maxn=f[i][j];
        }
      }
    cout<<maxn;
}

