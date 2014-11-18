#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=101;
const int infinity=100000001;
int D[maxn][maxn];
int G[maxn][maxn];
int mincircle;
int n,m;

void floyd()
{for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
      D[i][j]=G[i][j];
 for(int k=1;k<=n;++k)
  {
    //新增部分:
    for(int i=1;i<k-1;++i)
        for(int j=i+1;j<k;++j)
            {mincircle = min(mincircle,D[i][j]+G[j][k]+G[k][i]);
            }
    //通常的 floyd 部分:
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            //if(dist[i][j]+dist[j][i]<tmp)
            int temp = D[i][k] + D[k][j];
            if(temp < D[i][j])
                D[i][j]=D[j][i]=temp;
        }
  }
}

int main()
{int i,j,x,y,c,tn,tm;
 //freopen("p1046.in","r",stdin);
 tn=0; tm=0;
 while(scanf("%d %d",&n,&m)!=EOF)
    {for(i=1;i<=n;i++)for(j=1;j<=n;j++)G[i][j]=infinity;
     for(i=1;i<=m;i++)
       {scanf("%d %d %d",&x,&y,&c);
        G[x][y]=G[y][x]=c;
       }
     /*for(i=1;i<=n;i++)
       {for(j=1;j<=n;j++)
           if(G[i][j]=infinity)
            cout<<0<<' ';
           else
           cout<<G[i][j]<<' ';
        cout<<endl;
       }*/
     mincircle=infinity;
     floyd();
     if(mincircle==infinity)
       cout<<"No solution.\n";
     else
     cout<<mincircle<<endl;
    }
 //while(1) ;
 return 0;
}
