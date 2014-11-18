#include<stdio.h>
int a[11],f[11][11][2],sign[11];
int min(int i,int j){
    return(i<j?i:j);
}
int max(int i,int j){
    return(i>j?i:j);
}
int dp(int i,int j,int p){
    if(f[i][j][p]>-1001&&f[i][j][p]<1001) return(f[i][j][p]);
    int k,m,x,y,z;
    if(p==0){
        m=-1001;
        for(k=i;k<j;k++){
            x=dp(i,k,0)+sign[k+1]*dp(k+1,j,0);
            y=dp(i,k,0)+sign[k+1]*dp(k+1,j,1);
            z=max(x,y);
            if(z>m) m=z;
        }
        f[i][j][p]=m;
        return(m);
    }
    else if(p==1){
        m=1001;
        for(k=i;k<j;k++){
            x=dp(i,k,1)+sign[k+1]*dp(k+1,j,0);
            y=dp(i,k,1)+sign[k+1]*dp(k+1,j,1);
            z=min(x,y);
            if(z<m) m=z;
        }
        f[i][j][p]=m;
        return(m);
    }
}
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int i,j,n,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            f[i][j][0]=-1001;
            f[i][j][1]=1001;
        }
    }
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>=0) sign[i]=1;
        else sign[i]=-1;
        if(a[i]<0) a[i]=-a[i];
        f[i][i][0]=f[i][i][1]=a[i];
    }
    printf("%d",dp(1,n,0));
    /*for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d %d\n",f[i][j][0],f[i][j][1]);
        }
        printf("\n");
    }*/
}

