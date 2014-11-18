#include<iostream>
using namespace std;

int n,r=1,r2=0;

void dfs(int s,int last,int w)
{
if(w==r)
{
if(s>=n)
r2++;
return;
}
int t=s;
for(int i=1;i<=r-w;i++)
t*=2,t+=1;
if(t>=n)
{
for(int i=last+1;i<=s+1;i++)
dfs(s+i,i,w+1);
}
}


int main()
{
cin>>n;
int t=2;
while(!(n<=t-1))
r++,t*=2;

dfs(0,0,0);
cout<<r<<" "<<r2<<endl;

return 0;
}

