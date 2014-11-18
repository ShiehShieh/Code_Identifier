#include <iostream>
#define MAXN 300
using namespace std;
struct node{
int l,r,s,d;
} tree[MAXN+1];
int f[MAXN+1][MAXN+2],n,m,p1[MAXN+1],p2[MAXN+1];
void build(int x){
int i,k=x;
tree[x].d=p2[x];
for(i=1;i<=n;++i)
if(p1[i]==x){
if(k==x)
tree[x].l=i;
else
tree[k].r=i;
build(i);
k=i;
}
}
void travel(int x){
if(tree[x].l){
travel(tree[x].l);
tree[x].s+=tree[tree[x].l].s;
}
if(tree[x].r){
travel(tree[x].r);
tree[x].s+=tree[tree[x].r].s;
}
tree[x].s++;
}
int solve(int x,int k){
int i,ma=0,left=tree[x].l,right=tree[x].r;
if(k<=0)return 0;
if(f[x][k]!=0)return f[x][k];
if(tree[x].s==1)return f[x][k]=tree[x].d;
if(right && tree[right].s>=k)                //left.num=0，这时left不是必须存在
ma=max(ma,solve(right,k));
if(right && tree[right].s>=k-1)
ma=max(ma,solve(right,k-1)+tree[x].d);
if(left){
for(i=1;i<=k-2;++i)                        //left.num=i
if(tree[left].s>=i){
if(right && tree[right].s>=k-1-i)
ma=max(ma,solve(left,i)+tree[x].d+solve(right,k-1-i));
}else break;
ma=max(ma,solve(left,k-1)+tree[x].d);          //把 k-1-i=0 拿出来是因为这时right不是必须存在
}
return f[x][k]=ma;
}
int main(){
int i;
cin>>n>>m;
for(i=1;i<=n;++i)
cin>>p1[i]>>p2[i];
build(0);
travel(tree[0].l);
cout<<solve(tree[0].l,m)<<endl;
return 0;
}
