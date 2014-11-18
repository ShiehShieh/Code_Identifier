#include<iostream>
using namespace std;

int linked1[201][201];
int dist1[201][201];
int linked2[201][201];
int dist2[201][201];
int r1[201];
int r2[201];
int n;
bool fw[201];

void dfs1(int w)
{
fw[w]=1;
for(int i=1;i<=linked1[w][0];i++)
{
int t=linked1[w][i];
if(!fw[t])
if(r1[t]<r1[w]+dist1[w][i])
{
r1[t]=r1[w]+dist1[w][i];
dfs1(t);
}
}
fw[w]=0;
}

int res[101];

void dfs2(int w)
{
fw[w]=1;
for(int i=1;i<=linked2[w][0];i++)
{
int t=linked2[w][i];
if(!fw[t])
if(r2[t]<r2[w]+dist2[w][i])
{
r2[t]=r2[w]+dist2[w][i];
dfs2(t);
}
}
fw[w]=0;
}

int main()
{
res[0]=0;
memset(r1,0,sizeof(r1));
memset(r2,0,sizeof(r2));
memset(fw,0,sizeof(fw)); 
cin>>n;
n++;
int m,a,b,c;
cin>>m;
for(int i=1;i<=m;i++)
{
cin>>a>>b>>c;
linked1[a][++linked1[a][0]]=b;
dist1[a][linked1[a][0]]=c;
swap(a,b);
linked2[a][++linked2[a][0]]=b;
dist2[a][linked2[a][0]]=c;
}
dfs1(1);
memset(fw,0,sizeof(fw)); 
dfs2(n);
int len=r1[n];
for(int i=1;i<=n;i++)
if(r1[i]+r2[i]==len)
res[++res[0]]=i;
cout<<len<<endl;
for(int i=1;i<=res[0];i++)
{
cout<<res[i];
if(i<res[0])
cout<<" ";
else
cout<<endl;
}


return 0;
}

