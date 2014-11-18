#include <stdio.h>
int work(int x){
    int i,l;
    for (i=0;i<x;i++) scanf("%d",&l);
    return 0;
}
int main(){
    int k,n,i;
    scanf("%d",&k);
    int a[k];
    for (i=0;i<k;i++){
        scanf("%d",&n);
        scanf("%d",&a[i]);
        work(n);
        }
    for (i=0;i<k;i++){
        if (a[i]==1) printf("lolanv\n");
        else printf("wind\n");
        }
    return 0;
}

