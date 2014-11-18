#include <stdio.h>
#include <string.h>
int g[101][101],dist[101][101];
int n,m;
int main(){
    int i,j,k,a,b,c,minn,x=0,y=1;
    while (scanf("%d%d",&n,&m)!=EOF){
          for (i=1;i<=n;i++) for (j=1;j<=n;j++) dist[i][j]=100000000;
          for (i=1;i<=m;i++) {scanf("%d%d%d",&a,&b,&c);dist[a][b]=dist[b][a]=c;}
          memcpy(g,dist,sizeof(dist));minn=100000000;
          for (k=1;k<=n;k++){
              for (i=1;i<k;i++)
                  for (j=i+1;j<k;j++)
                      if(g[i][j]+dist[i][k]+dist[k][j]<minn) minn=g[i][j]+dist[i][k]+dist[k][j];
              for (i=1;i<=n;i++)
                  for (j=1;j<=n;j++)
                      if(g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
          }
          if(minn==100000000) printf("No solution.\n");
          else printf("%d\n",minn);
    }
    return 0;
}

