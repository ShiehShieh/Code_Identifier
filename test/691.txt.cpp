#include<iostream>
#include<fstream>
using namespace std;

int n,m,now;
bool d[100001];
int a[100001],b[100001],c[100001];
bool Find=1;

int main()
{ 
cin>>n>>now>>m;
memset(d,0,sizeof(d));
d[now]=1;
for(int i=1;i<=m;i++)
scanf("%d %d %d",&a[i],&b[i],&c[i]);
//cin>>a[i]>>b[i]>>c[i];

for(int i=m+1;i<=2*m;i++)
{
a[i]=a[2*m-i+1];
b[i]=b[2*m-i+1];
c[i]=c[2*m-i+1];
}
m=2*m;

while(Find)
{


Find=0;
int i=0;
while(i<m)
{
i++;
if(d[a[i]])
{
if(d[b[i]])
{
a[i]=a[m];
b[i]=b[m];
c[i]=c[m];
m--;
i--;
}
else
if(d[c[i]])
{
d[b[i]]=1,Find=1;
a[i]=a[m];
b[i]=b[m];
c[i]=c[m];
m--;
i--;
}
}
else
if(d[b[i]] && d[c[i]])
{
d[a[i]]=1,Find=1;
a[i]=a[m];
b[i]=b[m];
c[i]=c[m];
m--;
i--;
}
}
}
for(int i=1;i<=n;i++)
if(d[i])
printf("%d:Yes",i);
//cout<<i<<":Yes\n";
else
printf("%d:No",i);
//cout<<i<<":No\n";


return 0;
}
