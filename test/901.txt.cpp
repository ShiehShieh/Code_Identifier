#include<iostream>
using namespace std;
int f[31][31];
int main(){
    int m,n;
    int i,j;
    cin>>n>>m;
    f[1][0]=1;
    for(j=1;j<=m;j++)
      {f[1][j]=f[n][j-1]+f[2][j-1];
      for(i=2;i<=n-1;i++)
        f[i][j]=f[i-1][j-1]+f[i+1][j-1];
      f[n][j]=f[n-1][j-1]+f[1][j-1];
      }
    cout<<f[1][m];
    return 0;
}

