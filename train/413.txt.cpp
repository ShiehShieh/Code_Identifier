#include<stdio.h>
int a[1000];
int cj[10000],len=1;
void chen(int x){
    int i;
    for(i=1;i<=len;i++){
        cj[i]*=x;
    }
    for(i=1;i<=len;i++){
        if(cj[i]>=10){
            cj[i+1]+=(cj[i]/10);
            cj[i]%=10;
        }
    }
    i=len+1;
    while(cj[i]){
        if(cj[i]>=10){
            cj[i+1]+=(cj[i]/10);
            cj[i]%=10;
        }
        i++;
    }
    if(cj[i]==0) i--;
    len=i;
}
void work(int s){
    int i;
    cj[1]=1;
    for(i=1;i<=s;i++){
        chen(a[i]);
    }
    printf("\n");
    for(i=len;i>=1;i--){
        printf("%d",cj[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int s,i,j,k;
    s=0;
    i=2;
    while(s<=n){
        s=s+i;
        i++;
    }
    i--;
    s-=i;
    i--;
    for(j=1;j<i;j++){
        a[j]=j+1;
    }
    k=i-1;
    for(j=s+1;j<=n;j++){
        a[k]++;
        k--;
        if(k==0) k=i-1;
    }
    for(j=1;j<i;j++) printf("%d ",a[j]);
    work(i-1);
    //while(1);
}

