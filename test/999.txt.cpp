#include<iostream>
using namespace std;

struct Edge
{
int a;
int b;
int k;
int len;
}E[100001];

int n,m;
int s,t;
int tl;
int rec_k[5001],rec_t[5001];
int STR[5001],END[5001];
int res=100000000;

int cmp(const void *a,const void *b)
{
return (*(Edge*)a).a - (*(Edge*)b).a;
}

void dfs(int w,int s,int tl)
{
if(tl<0)
return;

if(w==t)
{
res=min(res,s);
return;
}
if(s>rec_t[w] && tl<rec_k[w])
return;
rec_t[w]=min(rec_t[w],s);
rec_k[w]=max(rec_k[w],tl);
for(int i=STR[w];i<=END[w];i++)
dfs(E[i].b,s+E[i].len,tl-E[i].k);
}

int main()
{
memset(STR,0xe,sizeof(STR));
memset(END,0,sizeof(END));
memset(rec_k,0,sizeof(rec_k));
memset(rec_t,0xe,sizeof(rec_t));
cin>>n>>m;
for(int i=1;i<=m;i++)
cin>>E[i].a>>E[i].b>>E[i].k>>E[i].len;
for(int i=m+1;i<=m+m;i++)
E[i]=E[i-m],swap(E[i].a,E[i].b);
m+=m;
qsort(E+1,m,sizeof(E[0]),cmp);
for(int i=1;i<=m;i++)
STR[E[i].a]=min(STR[E[i].a],i),END[E[i].a]=i;
cin>>s>>t>>tl;
dfs(s,0,tl);
if(res>=100000000)
cout<<-1<<endl;
else
cout<<res<<endl;

return 0;
}

