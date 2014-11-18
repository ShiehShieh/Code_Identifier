#include<iostream>
using namespace std;

struct BN
{
int x[301];
BN operator *(int u)
{
BN r;
for(int i=0;i<=300;i++)
r.x[i]=x[i]*u;
for(int i=0;i<300;i++)
r.x[i+1]+=r.x[i]/10,r.x[i]%=10;
return r;
}
}S;

int x[100001],z=0;

int main()
{
S.x[0]=1;
int n;
cin>>n;
int s=2,t=n;
while(t>=s)
{
x[++z]=s;
t-=s;
s++;
}
while(t)
for(int i=z;i>0 && t>0;i--)
{
x[i]++;
t--;
}
for(int i=1;i<=z;i++)
{
cout<<x[i];
S=S*x[i];
if(i<z)
cout<<" ";
else
cout<<endl;
}
bool ok=0;
for(int i=300;i>=0;i--)
{
if(S.x[i]>0 || i==0)
ok=1;
if(ok)
cout<<S.x[i];
}
cout<<endl;
return 0;
}

