#include<iostream>
using namespace std;
int n,m;
struct town
{
       int l,r,d,t;
}a[1001];
int dp[101][101][101];
int work(int s,int x,int k,int y)
{
     if(dp[y][x][k]!=-1)return dp[y][x][k];
     int t1=20000000,t2=20000000;
     if(a[x].l==-1&&a[x].r==-1)
     {
     if(k<=0)return (s+a[x].t)*a[x].d;else return 0;
     }
     if(a[x].r==-1)
     {
     if(k>0&&x!=0)t1=work(0,a[x].l,k-1,x);
     t2=(s+a[x].t)*a[x].d+work(s+a[x].t,a[x].l,k,y);
     if(t1<t2)t2=t1;
     dp[y][x][k]=t2;
     return t2;
     }
     if(a[x].l==-1)
     {
     t1=(s+a[x].t)*a[x].d+work(s,a[x].r,k,y);
     if(k>0)t2=work(s,a[x].r,k-1,y);
     if(t1<t2)t2=t1;
     dp[y][x][k]=t2;
     return t2;
     }
     int i;
     t2=20000000;
     for(i=0;i<=k;i++)
     {
     t1=(s+a[x].t)*a[x].d+work(s+a[x].t,a[x].l,i,y)+work(s,a[x].r,k-i,y);
     if(t1<t2)t2=t1;
     if(i<k)t1=work(0,a[x].l,i,x)+work(s,a[x].r,k-i-1,y);
     if(t1<t2)t2=t1;
     if(i>0)t1=work(0,a[x].l,i-1,x)+work(s,a[x].r,k-i,y);
     if(t1<t2)t2=t1;
     }
     dp[y][x][k]=t2;
     return t2;
}
int main(void)
{
    int i,x,y,z,j,k;
    cin>>n>>m;
    for(i=0;i<=n;i++)
    for(j=0;j<=n;j++)
    for(k=0;k<=n;k++)
    dp[i][j][k]=-1;
    for(i=0;i<=n;i++)a[i].l=a[i].r=-1;
    a[0].d=0;a[0].t=0;
    for(i=1;i<=n;i++)
    {
                     cin>>x>>y>>z;
                     a[i].r=a[y].l;
                     a[y].l=i;
                     a[i].d=x;
                     a[i].t=z;
                     }
    cout<<work(0,0,m,0);
}

