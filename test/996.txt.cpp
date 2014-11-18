#include<stdio.h>
int f[101][202]={0};
char s[200][202];
int minn(int i,int j){
    return(i<j?i:j);
}
int min(int i,int j,int k){
    return(minn(minn(i,j),k));
}
int main(){
    int i,j,k,n,maxn=1;
    scanf("%d\n",&n);
    for(i=n;i>=1;i--){
        for(j=1;j<=i*2-1;j++){
            scanf("%c",&s[i][j]);
        }
        scanf("\n");
    }
    for(i=n;i>=1;i--){
        for(j=1;j<=i*2-1;j++){
            if(s[i][j]=='-'){
                f[i][j]=min(f[i+1][j],f[i+1][j+1],f[i+1][j+2])+1;
            }
            else f[i][j]=0;
            if(f[i][j]>maxn&&j%2==1) maxn=f[i][j];
        }
    }
    printf("%d",maxn*maxn);
}

