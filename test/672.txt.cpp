#include<iostream>
using namespace std;
int a[1001][1001],n,m,f[1001][1001],i,j,k,w;
int main(){
    cin>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    cin>>a[i][j];
    for(i=0;i<=n;i++)
    for(j=0;j<=m;j++)
    f[i][j]=0;
    w=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
if(a[i][j]==1)
{
f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
w=max(f[i][j], w);
}
}
    cout<<w;
    return 0;
}
