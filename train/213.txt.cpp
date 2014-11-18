#include<iostream>
using namespace std;

long n,m,a[501][501],f[501][501],MAX;
const long d[4][2]={0,-1,-1,0,0,1,1,0};
long dfs(long x,long y){
    if(f[x][y]) return f[x][y];
    long t,tmp;
    t=1;
    for(long i=0;i<4;++i)
        if(d[i][0]+x>=1&&d[i][0]+x<=n&&d[i][1]+y>=1&&d[i][1]+y<=m)
            if(a[d[i][0]+x][d[i][1]+y]>a[x][y]){
                tmp=dfs(d[i][0]+x,d[i][1]+y)+1;
                if(tmp>t) t=tmp;
            }
    f[x][y]=t;
    return t;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(long i=1;i<=n;++i)
        for(long j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
            f[i][j]=0;
        }
    MAX=0;
    for(long i=1;i<=n;++i)
        for(long j=1;j<=m;++j){
            long k=dfs(i,j);
            if(k>MAX) MAX=k;
        }
    printf("%d\n",MAX);
    return 0;
}

