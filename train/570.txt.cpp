#include <iostream>
#define MAXN 50
using namespace std;
int W[MAXN+1],n,S[MAXN+1],a[MAXN+1],res,ans,sum[MAXN+1];
bool G[MAXN+1][MAXN+1],b[MAXN+1];

void search(int x){
    int i;
    if(ans>=sum[x]+res || x==n+1)
        return;
    for(i=1;i<x;++i)
        if(b[i] && G[a[i]][a[x]])
            break;
    if(i==x){
        b[x]=true;
        res+=W[a[x]];
        ans=max(ans,res);
        search(x+1);
        res-=W[a[x]];
        b[x]=false;
    }
    search(x+1);
}

int main(){
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>W[i];
    while(cin>>i>>j){
        G[i][j]=true;
        G[j][i]=true;
        S[j]++; S[i]++;
    }
    for(i=n;i>=1;--i) a[i]=i;
    for(i=1;i<n;++i){
        k=i;
        for(j=i+1;j<=n;++j)
            if(S[a[k]]<S[a[j]])
                k=j;
        if(k!=i){
            j=a[i];
            a[i]=a[k];
            a[k]=j;
        }
    }
    for(i=n;i>=1;--i)
        sum[i]=sum[i+1]+W[a[i]];
    search(1);
    cout<<ans<<endl;
    return 0;
}

