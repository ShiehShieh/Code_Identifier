#include<iostream>
using namespace std;

int r=10000000;
int rec[51][51][51];
int x[51],w[51];
int n,c;

void dfs(int left,int right,int s,int loc)
{
if(rec[left][right][loc]>=s)
rec[left][right][loc]=s;
else
return;

if(s>r)
return;
if(left==1 && right==n)
r=min(r,s);
if(left>1)
dfs(left-1,right,s+abs(x[loc]-(x[left-1]))*(w[n]-(w[right]-w[left-1])),left-1);
if(right<n)
dfs(left,right+1,s+abs(x[loc]-(x[right+1]))*(w[n]-(w[right]-w[left-1])),right+1);
}


int main()
{
memset(rec,0xe,sizeof(rec));
cin>>n>>c;
w[0]=0;
for(int i=1;i<=n;i++)
cin>>x[i]>>w[i],w[i]+=w[i-1];
dfs(c,c,0,c);
cout<<r<<endl;

return 0;
}

