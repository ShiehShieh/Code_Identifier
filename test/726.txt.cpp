#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int f[1001][1001],n,m,s;
long long cost[1001]/*,times[1001]={0}*/;
int inq[1001]={0},queue[10001]={0},front=0,rear=1;
int done[1001]={0};
void dfs(int x,int t,int s){
     int i;
     //printf("x=%d t=%d s=%d\n",x,t,s);
     for (i=1;i<=n;i++)
         if(done[i]==t&&f[x][i]!=INT_MAX&&f[x][i]+s<0) {printf("-1");exit(0);}
         else if(done[i]==t&&f[x][i]!=INT_MAX&&f[x][i]+s>=0) return;
         else if(f[x][i]!=INT_MAX) {done[i]=t;dfs(i,t,s+f[x][i]);}
}
void spfa(){
     int x,i,j;
     for (i=1;i<=n;i++) cost[i]=LONG_LONG_MAX;
     cost[s]=0;
     while (front<rear){
           x=queue[front];
           //printf("%d %d %d\n",front,rear,x);
           inq[x]=0;
           for (i=1;i<=n;i++)
               if(f[x][i]!=INT_MAX&&cost[i]>cost[x]+f[x][i])
                 {cost[i]=cost[x]+f[x][i];//printf("i=%d cost=%d\n",i,cost[i]);
                  //times[i]++;if(times[i]>n) {printf("-1");exit(0);}
                  if(!inq[i]) {inq[i]=1;queue[rear++]=i;}
                 }
           front++;
     }
}
int main(){
    int i,j,k,a,b,c;
    //freopen("p1053in.txt","r",stdin);
    //freopen("p1053out.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&s);
    for (i=1;i<=n;i++) for (j=1;j<=n;j++) f[i][j]=INT_MAX;
    queue[front]=s;inq[s]=1;//f[s][s]=0;
    for (i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(c<f[a][b]) f[a][b]=c;
    }
    for (i=1;i<=n;i++) if(done[i]==0) {done[i]=i;dfs(i,i,0);}
    //for (i=1;i<=n;i++) printf("%d ",done[i]);
    spfa();
    for (i=1;i<=n;i++)
        if(cost[i]==LONG_LONG_MAX) printf("NoPath\n");
        else printf("%lld\n",cost[i]);
    return 0;
}

