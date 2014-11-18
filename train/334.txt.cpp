#include<stdio.h>
int a[100001],b[100001],g[100001],d[100001],num[200001];
int main(){
    int n,i,maxn=0,t;
    scanf("%d",&n);
    b[0]=g[0]=0;
    for(i=0;i<=100000+n;i++) num[i]=-1;
    num[100000]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=b[i-1];
        g[i]=g[i-1];
        if(a[i]==1) b[i]++;
        else g[i]++;
        d[i]=b[i]-g[i];
        t=d[i]+100000;
        if(num[t]!=-1){
            if(i-num[t]>maxn) maxn=i-num[t];
        }
        else num[t]=i;
    }
    printf("%d",maxn);
}

