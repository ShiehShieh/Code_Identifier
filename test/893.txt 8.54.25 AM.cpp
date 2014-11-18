#include<iostream>
using namespace std;

int n,m;
int c[201];
int u[201];
bool dt[201];
int linked[201][201];
int w[201][201];

int haveson[201];
int list[201];

void dfs(int wz)
{
if(dt[wz])
return;
dt[wz]=1;
if(linked[wz][0]==0)
return;
else
{
int s=0;
for(int i=1;i<=linked[wz][0];i++)
{
dfs(linked[wz][i]);
s+=c[linked[wz][i]]*w[wz][i];
}
s-=u[wz];
if(s<0)
s=0;
c[wz]=s;
}
}

int main()
{
memset(dt,0,sizeof(dt));
memset(linked,0,sizeof(linked));
memset(haveson,0,sizeof(haveson));
memset(w,0,sizeof(w));
cin>>n>>m;
for(int i=1;i<=n;i++)
cin>>c[i]>>u[i];
for(int i=1;i<=m;i++)
{
int a,b,ww;
cin>>a>>b>>ww;
haveson[a]=1;
linked[b][++linked[b][0]]=a;
w[b][linked[b][0]]=ww;
}
for(int i=1;i<=n;i++)
if(!haveson[i])
list[++list[0]]=i;

for(int i=1;i<=list[0];i++)
dfs(list[i]);

bool have=0;

for(int i=1;i<=list[0];i++)
if(c[list[i]])
have=1;
if(!have)
cout<<"NULL"<<endl;
else
{
for(int i=1;i<=list[0];i++)
if(c[list[i]])
cout<<list[i]<<" "<<c[list[i]]<<endl;
}
return 0;
}

