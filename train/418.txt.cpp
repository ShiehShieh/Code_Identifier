#include<stdio.h>
int a[10001][3],n,m,f[10001];
int ab(int x){
    return(x>0?x:-x);
}
int main(){
    int n,m,i,j,maxn=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        f[i]=1;
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    }
    for(i=2;i<=m;i++){
        for(j=1;j<i;j++){
            if(f[j]<=f[i]-1) continue;
            if(ab(a[i][1]-a[j][1])+ab(a[i][2]-a[j][2])<=(a[i][0]-a[j][0])){
                f[i]=f[j]+1;
            }
        }
        if(f[i]>maxn) maxn=f[i];
    }
    printf("%d",maxn);
}

