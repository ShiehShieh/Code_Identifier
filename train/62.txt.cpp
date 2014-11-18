#include<stdio.h>
int n,m,minn=2147483647;
struct{
    int x,y,z;
}a[10002];
int dist[101],p[101],map[101][101];
void dij(int v0){
    int i,j,x,y,z,mi=21474836,v1;
    for(i=1;i<=n;i++){
        dist[i]=map[v0][i];
        p[i]=0;
    }
    dist[v0]=0;
    for(i=1;i<n;i++){
        mi=21474836;
        for(j=1;j<=n;j++){
            if(p[j]==0&&dist[j]<mi){
                v1=j;
                mi=dist[j];
            }
        }
        if(mi==21474836) return;
        p[v1]=1;
        for(j=1;j<=n;j++){
            if(map[v1][j]+mi<dist[j]){
                dist[j]=map[v1][j]+mi;
            }
        }
    }
}
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int i,j,x,y,z;
    while(scanf("%d %d",&n,&m)!=EOF){
        minn=2147483647;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                map[i][j]=21474836;
            }
        }
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&x,&y,&z);
            a[i].x=x;a[i].y=y;a[i].z=z;
            map[x][y]=map[y][x]=z;
        }
        for(i=1;i<=m;i++){
            x=a[i].x;y=a[i].y;z=a[i].z;
            map[x][y]=map[y][x]=21474836;
            if(z>=minn) continue;
            dij(a[i].x);
            map[x][y]=map[y][x]=z;
            if(z+dist[y]<minn) minn=z+dist[y];
            //printf("%d\n",dist[y]);
        }
        if(minn>21474836) printf("No solution.\n");
        else printf("%d\n",minn);
    }
}

