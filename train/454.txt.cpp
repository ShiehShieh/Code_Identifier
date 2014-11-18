#include <stdio.h>
int min2(int a,int b){
    return (a<b)?a:b;
}
int min1(int a,int b,int c){
    return min2(a,min2(b,c));
}
int g[505][505];
int main(){
    int n,i,j,k,ans=0;
    //freopen("p1069in.txt","r",stdin);
    char s[600];
    scanf("%d\n",&n);
    for (i=1;i<=n;i++) for (j=1;j<=(n-i)*2+1;j++) g[i][j]=1;
    for (i=1;i<=n;i++){
        gets(s);
        for (j=1,k=i-1;j<=(n-i)*2+1;j++,k++) if(s[k]=='#') g[i][j]=0;
    }
    for (i=2;i<=n;i++)
        for (j=1;j<=(n-i)*2+1;j++)
            if(g[i][j]>0)
              {g[i][j]=min1(g[i-1][j],g[i-1][j+1],g[i-1][j+2])+1;
               if(g[i][j]>ans&&j%2==1) ans=g[i][j];
              }
    printf("%d",ans*ans);//while(1);
    return 0;
}
