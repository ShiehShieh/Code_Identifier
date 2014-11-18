#include<stdio.h>
#include<iostream>
#define maxn 2000000001
using namespace std;
int n,m,s;
int map[1001][1001],Q[20001],d[1001],ans[1001];
bool visit[1001];
void init(){
     //freopen("a.in","r",stdin);
     scanf("%d%d%d",&n,&m,&s);
     int a,b,c,i,j;
     for(i=1;i<=n;i++)for(j=1;j<=n;j++)map[i][j]=maxn;
     for(i=1;i<=m;i++){
                       scanf("%d%d%d",&a,&b,&c);
                       map[a][b]=min(c,map[a][b]);
                       }
     /*
     for(i=1;i<=n;i++){
                       for(j=1;j<=n;j++){
                                         printf("%10d ",map[i][j]);
                                         }
                       printf("\n");
                       }
                       */
     }
void intit(int m[],int n){
     int i;
     for(i=1;i<=n;i++)m[i]=maxn;
     }
int SPFA(int v){
     int i,j,tmp;
     
     memset(visit,false,sizeof(visit));
     visit[v]=true;
     
     intit(d,n);
     d[v]=0;
     
     int heap,rear;
     heap=rear=1;
     Q[heap]=v;
     while(heap<=rear){
                i=Q[heap++]; visit[i]=false;
                for(j=1;j<=n;j++){
                                  if(d[i]+map[i][j]<d[j]){
                                                          d[j]=d[i]+map[i][j];
                                                          if(!visit[j]){
                                                                        Q[++rear]=j;
                                                                        visit[j]=true;
                                                                        }
                                                          }
                                  if(d[v]<0)return 0;
                                  }
                //printf("\n");
                }
     return 1;
     }
int main(){
    init();
    if(SPFA(s)==0)printf("-1\n");
    else {
         int i;
         for(i=1;i<=n;i++) ans[i]=d[i];
         for(i=1;i<=n;i++)if(d[i]==maxn&&SPFA(i)==0){printf("-1\n");return 0;}
         for(i=1;i<=n;i++){
                           if(ans[i]<maxn)printf("%d\n",ans[i]);
                           else printf("NoPath\n");
                           }
         }
    //while(1);
    return 0;
    }


