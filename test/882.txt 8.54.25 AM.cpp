#include<iostream>
using namespace std;
__int64 f[200][40];
__int64 a[20000];
__int64 n,m;
__int64 ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        f[i][1]=1;
        for(int j=1;j<=m;j++)
          for(int k=1;k<i;k++)
          if(a[k]<a[i])f[i][j]+=f[k][j-1];
        ans+=f[i][m];
    }
    cout<<ans;
}
