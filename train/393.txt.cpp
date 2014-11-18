#include<iostream>
using namespace std;
long a[17][17];
long lx[17],ly[17],hy[17],hx[17],pre[17],slack[17];
long mm=0,n=0;
bool search(int x)
{
hx[x]=false;
for (int i=1;i<=n;i++)
if (hy[i])
{
long t=lx[x]+ly[i]-a[x][i];
if (t==0)
{
hy[i]=false;
if (pre[i]==0||search(pre[i])) {pre[i]=x;return true;}
}else if (slack[i]>t) slack[i]=t;
}
return false;
}
void init()
{
memset(a,255,sizeof(a));
int x1[17],y1[17];
memset(x1,false,sizeof(x1));
char ch;
for (int i=1;i<=4;i++)
for (int j=1;j<=4;j++)
{
cin>>ch;
if (ch=='1') {n++;x1[n]=i;y1[n]=j;}
}
int nn=0;
for (int i=1;i<=4;i++)
for (int j=1;j<=4;j++)
{
cin>>ch;
if (ch=='1'){
nn++;
for (int k=1;k<=n;k++)
{
a[k][nn]=abs(x1[k]-i)+abs(y1[k]-j);
if (mm<a[k][nn]) mm=a[k][nn];
}
}
}
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
a[i][j]=mm-a[i][j];
if (a[i][j]>lx[i]) lx[i]=a[i][j];
}
}
main()
{
memset(lx,0,sizeof(lx));
memset(ly,0,sizeof(ly));
memset(pre,0,sizeof(pre));
init();
for (int k=1;k<=n;k++)
while (true)
{
memset(hy,true,sizeof(hy));
memset(hx,true,sizeof(hx));
for (int i=0;i<=n;i++) slack[i]=2147483647;
if (search(k)) break;
long d=2147483647;
for (int i=1;i<=n;i++) if (slack[i]<d) d=slack[i];
for (int i=1;i<=n;i++)
{
if (!hx[i]) lx[i]-=d;
if (!hy[i]) ly[i]+=d;
}
}
long t=0;
for (int i=1;i<=n;i++) t+=lx[i]+ly[i];
cout<<mm*n-t<<endl;
return 0;
}
