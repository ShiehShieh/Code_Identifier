#include<iostream>
using namespace std;

int linked[301][301];
int son[301][301];
int n;
int r=9999;
/*
struct ST
{
int x[302];
}Y;
*/
int Y[301];


void dfs(int w,int root)
{
for(int i=1;i<=linked[w][0];i++)
if(linked[w][i]!=root)
{
son[w][++son[w][0]]=linked[w][i];
dfs(linked[w][i],w);
}
}

int m;

//void search(ST z,int s)
void search(int z[301],int s)
{
if(s>=r)
return;
//ST NEXT;
int x[301];
x[0]=0;
for(int i=1;i<=z[0];i++)
{
int t=z[i];
for(int j=1;j<=son[t][0];j++)
x[++x[0]]=son[t][j];
}
x[0]--;

if(x[0]<=0)
{
r=min(r,s);
return;
}
s+=x[0];
for(int i=1;i<=x[0]+1;i++)
{
swap(x[i],x[x[0]+1]);
search(x,s);
swap(x[i],x[x[0]+1]);
}
}

int main()
{
memset(linked,0,sizeof(linked));
memset(son,0,sizeof(son));
cin>>n>>m;
for(int i=1;i<n;i++)
{
int a,b;
cin>>a>>b;
linked[a][++linked[a][0]]=b;
linked[b][++linked[b][0]]=a;
}   
dfs(1,0);
/*
Y.x[0]=1;
Y.x[1]=1;*/
Y[0]=1;
Y[1]=1;

search(Y,1);
cout<<r<<endl;

return 0;
}

