/*
TASK:nuggets
NAME:chengaoyuan
LANG:C++
*/

#include<iostream>
#include<fstream>
using namespace std;

bool can[1234568];
int ys[3001],x[3001],z,n=0,m;
bool NEX=0;

int gcd(int a,int b)
{
if(b>a)
return gcd(b,a);
if(b==0)
return a;
return gcd(b,a%b);
}

bool ok=1;

int main()
{
memset(can,0,sizeof(can));
memset(ys,0,sizeof(ys));
cin>>z>>m;
for(int i=1;i<=z;i++)
{
int t;
cin>>t;
for(int i=max(1,t-m);i<=t;i++)
ys[i]=1;
}
for(int i=1;i<=3000;i++)
if(ys[i])
x[++n]=i;
for(int i=1;i<=n;i++)
{
if(x[i]==1)
ok=0;
}

int u=x[1];
for(int i=2;i<=n;i++)
u=gcd(u,x[i]);
if(u!=1)
ok=0;
if(!ok)
cout<<-1<<endl;
else
{
can[0]=1;
for(int i=1;i<=n;i++)
for(int j=x[i];j<=123456;j++)
if(can[j-x[i]])
can[j]=1;
for(int i=123456;i>=0;i--)
if(!can[i])
{
if(i>123450)
{
NEX=1;
break;
}
cout<<i<<endl;
break;
}
}
if(NEX)
{
memset(can,0,sizeof(can));
can[0]=1;
for(int i=1;i<=n;i++)
for(int j=x[i];j<=1234567;j++)
if(can[j-x[i]])
can[j]=1;
for(int i=1234567;i>=0;i--)
if(!can[i])
{
cout<<i<<endl;
break;
}
}

return 0;
}

