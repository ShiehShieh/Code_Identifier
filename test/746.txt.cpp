#include<stdio.h>
#include<math.h>
double time,a[1001][3],r[1001][3];
int n,m,tot=0;
int x[1001];
bool g[1001]={0},f[1001][1001];
int pan(int i,int j){
    double t;
    double x1,x2,y1,y2;
    x1=r[i][0]*1.0;y1=r[i][1]*1.0;
    x2=a[j][0]*1.0;y2=a[j][1]*1.0;
    t=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/r[i][2];
    if(t<=time) return(1);
    else return(0);
}
void init(){
    int i,j;
    scanf("%d %d %lf",&n,&m,&time);
    for(i=1;i<=m;i++){
        scanf("%lf %lf",&a[i][0],&a[i][1]);
    }
    for(i=1;i<=n;i++){
        scanf("%lf %lf %lf",&r[i][0],&r[i][1],&r[i][2]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            f[i][j]=pan(i,j);
        }
    }
}
int find(int i){
    int j,t;
    for(j=1;j<=m;j++){
        if(f[i][j]&&g[j]==0){
            g[j]=1;
            if(x[j]==0||find(x[j])){
                x[j]=i;
                return(1);
            }
        }
    }
    return(0);
}
void work(){
    int i,j,t,k,l;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++) g[j]=0;
        if(find(i)) tot++;
    }
}
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    init();
    work();
    printf("%d",tot);
}

