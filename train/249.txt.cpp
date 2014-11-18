#include<stdio.h>
int dist[1001][1001],n,m,s;
int a[1001][1001];
int path[1000000],num[1001][1001]={0},done[1001],f[1001]={0};
int last,pre;
int spfa(int v0){
    int i,j,x;
    for(i=1;i<=n;i++){
        dist[v0][i]=1000001;
        done[i]=0;
    }
    done[v0]=1;
    dist[v0][v0]=0;
    while(pre<=last){
        x=path[pre];
        for(i=1;i<=n;i++){
            if(a[x][i]!=1000001&&dist[v0][x]!=1000001&&dist[v0][i]>dist[v0][x]+a[x][i]){
                dist[v0][i]=dist[v0][x]+a[x][i];
                num[v0][i]++;
                if(done[i]==0){
                    last++;
                    path[last]=i;
                    done[i]=1;
                }
                if(num[v0][i]>n) return(1);
            }
        }
        done[x]=0;
        pre++;
        if(dist[v0][v0]<0) return(1);
    }
    return(0);
}
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    scanf("%d %d %d",&n,&m,&s);
    int i,j,x,y,z,v1=s;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]=1000001;
        }
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&z);
        if(z<a[x][y]) a[x][y]=z;
    }
    int t,l;
    while(1){
        last=pre=1;
        path[1]=s;
        l=spfa(s);
        if(l==1){
            printf("-1");
            return(0);
        }
        for(i=1;i<=n;i++){
            if(dist[s][i]!=1000001) f[i]=1;
        }
        t=0;
        for(i=1;i<=n;i++){
            if(f[i]==0){
                t=1;
                s=i;
                break;
            }
        }
        if(t==0) break;
    }
    s=v1;
    for(i=1;i<=n;i++){
        if(dist[s][i]==1000001) printf("NoPath\n");
        else if(i==s){
            printf("0\n");
        }
        else printf("%d\n",dist[s][i]);
    }
    /*for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%7d ",a[i][j]);
        }
        printf("\n");
    }*/
}

