#include<stdio.h>
#include<math.h>
double a[1000][2];
double suan(double x0,double y0,double x1,double y1){
    return(sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1)));
}
int done[1001]={0},n;
double tot=2147483647.0;
void dfs(int i,double s,int step){
    if(step==n){
        if(s<tot){
            tot=s;
        }
        return;
    }
    int j;
    for(j=1;j<=n;j++){
        if(done[j]==0){
            done[j]=1;
            dfs(j,s+suan(a[i][0],a[i][1],a[j][0],a[j][1]),step+1);
            done[j]=0;
        }
    }
}
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int i,j;
    double s=0.0,minn=0.0,x;
    scanf("%d",&n);
    scanf("%lf %lf",&a[1][0],&a[1][1]);
    for(i=2;i<=n;i++){
        scanf("%lf %lf",&a[i][0],&a[i][1]);
        s=s+suan(a[i-1][0],a[i-1][1],a[i][0],a[i][1]);
        //printf("%lf\n",suan(a[i-1][0],a[i-1][1],a[i][0],a[i][1]));
    }
    if(n<=10){
        done[1]=1;
        dfs(1,0.0,1);
        printf("%.3lf",tot);
        return(0);
    }
    s=s+suan(a[1][0],a[1][1],a[n][0],a[n][1]);
    //printf("%lf\n",s);
    for(i=1;i<n;i++){
            x=suan(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
            //printf("%lf ",x);
            if(x>minn) minn=x;
    }
    x=suan(a[1][0],a[1][1],a[n][0],a[n][1]);
    if(x>minn) minn=x;
    printf("%.3lf",s-minn);
    //while(1);
}

