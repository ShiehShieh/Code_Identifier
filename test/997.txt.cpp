#include<iostream>
#include<string>
using namespace std;

int B1[101],B2[101],F1[101],F2[101],t[101];
int r[32769],tem;
int n,m;
int queue[3000001],z=0,now=0;

int main()
{
memset(r,0xe,sizeof(r));
cin>>n>>m;
for(int u=1;u<=m;u++)
{
cin>>t[u];
string s;
tem=0;
cin>>s;
for(int i=0;i<n;i++)
tem*=2,tem+=(s[i]=='+');
B1[u]=tem;
tem=0;
for(int i=0;i<n;i++)
tem*=2,tem+=(s[i]=='-');
B2[u]=tem;
tem=0;
cin>>s;
for(int i=0;i<n;i++)
tem*=2,tem+=(s[i]!='-');
F1[u]=tem;
tem=0;
for(int i=0;i<n;i++)
tem*=2,tem+=(s[i]=='+');
F2[u]=tem;
}
r[(1<<n)-1]=0;
queue[0]=(1<<n)-1;
while(now<=z)
{
int CUR=queue[now];
for(int i=1;i<=m;i++)
{
if((CUR&B1[i])==B1[i] && (B2[i]&CUR)==0)
{
int NEXT=(CUR&F1[i])|F2[i];
if(r[NEXT]>r[CUR]+t[i])
{
r[NEXT]=r[CUR]+t[i];
queue[++z]=NEXT;
}
}
}
now++;
}
if(r[0]>=r[32768])
r[0]=0;
cout<<r[0]<<endl;

return 0;
}

