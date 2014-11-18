#include <iostream>

using namespace std;
long long a[30][30];
int main()
{int m0,n0,i,j,m,n;
cin>>n>>m;
for(i=2;i<=n+2;i++)
for(j=2;j<=m+2;j++)
a[i][j]=-1;
a[2][2]=1;
cin>>n0>>m0;
n0=n0+2;
m0=m0+2;
a[n0][m0]=0;

 a[n0+2][m0+1]=0;
 a[n0+2][m0-1]=0;
 a[n0-2][m0+1]=0;
 a[n0-2][m0-1]=0;
 a[n0-1][m0+2]=0;
 a[n0-1][m0-2]=0;
 a[n0+1][m0-2]=0;
 a[n0+1][m0+2]=0;
for(i=0;i<=n+2;i++)
for(j=0;j<=m+2;j++)
if(a[i][j]==-1)
a[i][j]=a[i-1][j]+a[i][j-1];


cout<<a[n+2][m+2];

return 0;
}
