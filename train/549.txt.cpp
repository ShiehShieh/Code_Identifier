#include <iostream>
using namespace std;

int n,to;
int f[101],t[101];
long opt[1001];
long max(long a,long b);

int main(){
    cin>>n>>to;
    for (int i=1;i<=n;i++) cin>>f[i]>>t[i];
    for (int i=1;i<=to;i++) opt[i]=-1;
    opt[0]=0;
    for (int i=1;i<=n;i++)
        for (int j=to;j>=t[i];j--)
            if (opt[j-t[i]]!=-1) opt[j]=max(opt[j],opt[j-t[i]]+f[i]);
    long maxf=0;
    for (int i=1;i<=to;i++) maxf=max(maxf,opt[i]);
    cout<<maxf<<endl;
    return 0;
}
long max(long a,long b){
     if (a>b) return a;
     return b;
}

