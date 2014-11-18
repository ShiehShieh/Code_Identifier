#include<iostream>
#include<cmath>
#include<string>
using namespace std;
__int64 n,m,fi[2000],ti[2000],ans[2000][2000];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>fi[i]>>ti[i];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      {
              if(ti[i]<=j)
              {
                  if(fi[i]+ans[i-1][j-ti[i]]>ans[i-1][j])
                  ans[i][j]=fi[i]+ans[i-1][j-ti[i]];
                  else ans[i][j]=ans[i-1][j];
              }
              else  ans[i][j]=ans[i-1][j];
      }
    cout<<ans[n][m];
}

