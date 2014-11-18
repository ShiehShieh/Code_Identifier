#include <stdio.h>
int n,d;
int f[2501]={0},g[2501]={0};
int abs(int x){
    return (x>0)?x:-x;
}
int main(){
    //freopen("p1331in.txt","r",stdin);
    scanf("%d %d\n",&n,&d);
    int i,j;
    char s[2];
    for (i=1;i<=n;i++) {gets(s);if(s[0]=='J') g[i]=g[i-1]+1; else g[i]=g[i-1]-1;}
    //for (i=1;i<=n;i++) printf("i=%d value=%d\n",i,g[i]);
    for (i=1;i<=n;i++){
        f[i]=1000000;
        for (j=0;j<i;j++)
            if(f[i]>f[j]+1&&(abs(g[i]-g[j])<=d||abs(g[i]-g[j])==i-j)) f[i]=f[j]+1;
    }
    printf("%d",f[n]);
    //while(1);
    return 0;
}
            

