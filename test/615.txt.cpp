#include <iostream>
#define MAXN 32000
#define MAXM 60
using namespace std;

int f1[MAXN+1],f2[MAXN+1],v[MAXM+1],w[MAXM+1],q[MAXM+1],n,m;
struct node{
    int l,r;
} p[MAXM+1];

int main(){
    int i,j,t;
    cin>>n>>m;
    for(i=1;i<=m;++i){
        cin>>v[i]>>w[i]>>q[i];
        if(p[q[i]].l==0)
            p[q[i]].l=i;
        else
            p[q[i]].r=i;
    }

    for(i=1;i<=m;++i)
        if(q[i]==0){
            for(j=n;j>=v[i];--j){
                f2[j]=f1[j-v[i]]+v[i]*w[i];
                f1[j]=max(f2[j],f1[j]);
            }
            if(p[i].l){
                t=p[i].l;
                for(j=n;j>=v[i]+v[t];--j){
                    f2[j]=max(f2[j],f2[j-v[t]]+v[t]*w[t]);
                    f1[j]=max(f2[j],f1[j]);
                }
            }
            if(p[i].r){
                t=p[i].r;
                for(j=n;j>=v[i]+v[t];--j){
                    f2[j]=max(f2[j],f2[j-v[t]]+v[t]*w[t]);
                    f1[j]=max(f2[j],f1[j]);
                }
            }
        }

    cout<<f1[n]<<endl;
    return 0;
}


