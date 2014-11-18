#include <iostream>
#define MAXN 1500
using namespace std;
int h[MAXN+1],mem[MAXN+1],w[MAXN+1],n,f1[MAXN+1],f2[MAXN+1],f3[MAXN+1];
bool ist[MAXN+1];
void solve(int x){
int i=h[x],m=200000000;
bool f=true;
f1[x]=w[x];
while(i){
solve(i);
f1[x]+=min(min(f1[i],f2[i]),f3[i]);
if(f1[i]<=f2[i] || h[i]==0){
f2[x]+=f1[i];
f=false;
}
else f2[x]+=f2[i];
if(f && m>f1[i]-f2[i])                   //为f2[x]必须满足的有f1[x.sons]的条件做的小处理
m=f1[i]-f2[i];
if(h[i]==0)
f3[x]=1000000000;
else
f3[x]+=f2[i];
i=mem[i];
}
if(h[x]!=0 && f)                             //还是为f2[x]做的处理
f2[x]+=m;
}
int main(){
int i,x,k,j,m;
cin>>n;
for(i=1;i<=n;++i){
cin>>x>>k>>m;
w[x]=k;
for(j=1;j<=m;++j){
cin>>k;
mem[k]=h[x];
h[x]=k;
ist[k]=true;
}
}
for(i=1;i<=n;++i)
if(!ist[i])
break;
solve(i);
if(h[i]!=0)                                          //不要忘记一些边界情况
cout<<min(f1[i],f2[i]);
else
cout<<f1[i]<<endl;}
