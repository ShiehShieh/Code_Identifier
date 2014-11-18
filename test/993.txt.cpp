/*
TASK:fence8
NAME:chengaoyuan
LANG:C++
*/

#include<iostream>

using namespace std;

int yl[51],n;//原料
int x[1024],m;//需要切成的材料
int sum=0,use;

int cmp(const void *a,const void *b) 
{
return *(int*)a-*(int*)b;
}

int cmp2(const void *a,const void *b) 
{
return *(int*)b-*(int*)a;
}

inline bool dfsid(int now,int last)//now:当前要安放第几块了 last:上次放在哪 
{
if(now>m)
return 0;

if(use<0)
return 0;

if(!now)
return 1;

int s=1;
if(x[now]==x[now-1])
s=last;
for(int i=s;i<=n;i++)
if(yl[i]>=x[now])
{
yl[i]-=x[now];
if(yl[i]<x[1])
use-=yl[i];
if(dfsid(now-1,i))
{
yl[i]+=x[now];
return 1;
}
if(yl[i]<x[1])
use+=yl[i];
yl[i]+=x[now];
}
return 0;
}

int main()
{


x[0]=-1;
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>yl[i];
sum+=yl[i];
}
qsort(yl+1,n,sizeof(yl[0]),cmp2);
cin>>m;
int M=m;
for(int i=1;i<=m;i++)
cin>>x[i];
qsort(x+1,m,sizeof(x[0]),cmp);
bool ok=0;

for(int i=1;i<=m+1;i++)
{
use=sum;
for(int j=1;j<=i;j++)
use-=x[j];
if(!dfsid(i,0))
{
ok=1;
cout<<i-1<<endl;
break;
}
}

return 0;
}

