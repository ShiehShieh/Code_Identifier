#include<iostream>
#define WS 7
#define JZ 100000000
using namespace std;

struct BN
{
long int N[WS+1];
BN operator +(BN u)
{
for(int i=0;i<=WS;i++)
u.N[i]+=N[i];
for(int i=0;i<WS;i++)
u.N[i+1]+=u.N[i]/JZ,u.N[i]%=JZ;
return u;
}
}r[1500002];

void opt(int u)
{
int m=10;
while(m<JZ)
{
if(u<m)
printf("0");
m*=10;
}
printf("%d",u);
}


void output(BN u)
{
for(int i=WS;i>=0;i--)
if(i==0 || u.N[i]>0)
{
printf("%d",u.N[i]);
for(int j=i-1;j>=0;j--)
opt(u.N[j]);
//cout<<u.N[j];
return ;
}
return ;
}

int main()
{
r[0].N[0]=1;
for(int i=1;i<=1500000;i++)
r[i]=r[i-1]+r[i/2];
int n;
while(cin>>n)
{
output(r[n/2]);
cout<<endl;
}

return 0;
}

