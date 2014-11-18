#include<iostream>
using namespace std;
int a[51][51],f[101][51][51],i,j,k,m,n;
int dp(int dep,int x1,int x2)
{
    int s=-1,s1;
    if(x1<1||x2<1||x1>m||x2>m||dep<=x1||dep<=x2)return -1;
    if(dep==2&&x1==1&&x2==1)return 0;
    if(!(dep==m+n&&x1==m&&x2==m)&&x1==x2)return -1;
    if(f[dep][x1][x2]!=-1)return f[dep][x1][x2];
    s1=dp(dep-1,x1,x2);
    if(s1>s)s=s1;
    s1=dp(dep-1,x1-1,x2);
    if(s1>s)s=s1;
    s1=dp(dep-1,x1,x2-1);
    if(s1>s)s=s1;
    s1=dp(dep-1,x1-1,x2-1);
    if(s1>s)s=s1;
    s=s+a[x1][dep-x1]+a[x2][dep-x2];
    f[dep][x1][x2]=s;
    return s;
}
int main()
{
    int s;
    cin>>m>>n;
    for(i=1;i<=m;i++)for(j=1;j<=n;j++)cin>>a[i][j];
    for(i=1;i<=m+n;i++)for(j=1;j<=m;j++)for(k=1;k<=m;k++)f[i][j][k]=-1;
    f[2][1][1]=0;
    s=dp(m+n,m,m);
    cout<<s<<endl;
    return 0;
}
