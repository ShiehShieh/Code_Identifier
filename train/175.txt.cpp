#include<iostream>
using namespace std;

int m[51];
int rank[51];
int linked[51][51];
int r=0;
int n;

struct B
{
bool ban[51];
}T;

int cmp(const void *a,const void *b)
{
return m[*(int*)b] - m[*(int*)a];
}

void dfs(int wz,B s,int now)
{
int w=rank[wz];
now+=m[w];
r=max(r,now);
for(int i=1;i<=linked[w][0];i++)
s.ban[linked[w][i]]=1;
int ma=0;
for(int i=wz+1;i<=n;i++)
if(!s.ban[rank[i]])
ma+=m[rank[i]];

if(now+ma > r)
{
for(int i=wz+1;i<=n;i++)
if(!s.ban[rank[i]])
{
dfs(i,s,now);
}
}
}

int main()
{
memset(linked,0,sizeof(linked));
cin>>n;
m[0]=0;
for(int i=1;i<=n;i++)
cin>>m[i],rank[i]=i;
int a,b;
while(cin>>a>>b)
{
if(a*b==0)
break;
linked[a][++linked[a][0]]=b;
linked[b][++linked[b][0]]=a;
}
rank[0]=0;
qsort(rank+1,n,sizeof(rank[0]),cmp);
dfs(0,T,0);
cout<<r<<endl;

return 0;
}

