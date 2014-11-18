#include<iostream>
using namespace std;

struct M
{
int x[301];
}R[301];
int son[301][301],s[301];

int n,m;

M search(int w)
{
M t;
for(int i=0;i<=m;i++)
t.x[i]=-99999;
t.x[0]=0;
for(int i=1;i<=son[w][0];i++)
{
M u=search(son[w][i]);

for(int j=m;j>=1;j--)
for(int k=1;k<=j;k++)
t.x[j]=max(t.x[j],t.x[j-k]+u.x[k]); 

}
if(w)
{
for(int i=m;i>=1;i--)
t.x[i]=t.x[i-1]+s[w];
}

return t;
}

int main()
{
memset(son,0,sizeof(son));
cin>>n>>m;

for(int i=1;i<=n;i++)
{
int a;
cin>>a>>s[i];
son[a][++son[a][0]]=i;
}
M r=search(0);
cout<<r.x[m]<<endl;

return 0;
}

