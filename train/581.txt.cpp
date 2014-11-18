#include<cstdio>

struct edgetype
{
    long ver,next;
};

long i,j,k,l,m,n,p,q,s,t,x,y;
long head[101]={0},depth[101]={0},w[101],v[101],d[101];
edgetype edge[101];
long stack[101]={0};
long f[2][102][102][51]={0};
bool flag[101]={0},visited[101]={0};

using namespace std;

int main()
{
    scanf("%ld%ld",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%ld%ld%ld",&w[i],&v[i],&d[i]);
        edge[i].next=head[v[i]];
        edge[i].ver=i;
        head[v[i]]=i;
    }
    p=1;
    stack[1]=0;
    depth[0]=0;
    t=0;
    while (p)
    {
        i=stack[p];
        if (!visited[i])
        {
            for (x=p;x>=1;x--)
            {
                f[0][i][stack[x]][0]=w[i]*(depth[i]-depth[stack[x]]);
                for (y=1;y<=m;y++) f[0][i][stack[x]][m]=(1<<31)-1;
            }
            visited[i]=1;
        }
        if (head[i])
        {
            stack[++p]=edge[head[i]].ver;
            head[i]=edge[head[i]].next;
            t+=d[stack[p]];
            depth[stack[p]]=t;
        }
        else
          if (!i) p=0;
          else
          {
            for (k=p-1;k>=1;k--)
            {
                j=stack[k];
                for (x=0;x<=m;x++) f[flag[v[i]]^1][v[i]][j][x]=(1<<31)-1;
                for (x=0;x<=m;x++)
                  for (y=0;y<=x;y++)
                  {
                      if (f[flag[v[i]]][v[i]][j][x-y]<(1<<31)-1 && f[flag[i]][i][j][y]<(1<<31)-1) f[flag[v[i]]^1][v[i]][j][x]<?=f[flag[v[i]]][v[i]][j][x-y]+f[flag[i]][i][j][y];
                      if (y>0 && f[flag[v[i]]][v[i]][j][x-y]<(1<<31)-1 && f[flag[i]][i][i][y-1]<(1<<31)-1) f[flag[v[i]]^1][v[i]][j][x]<?=f[flag[v[i]]][v[i]][j][x-y]+f[flag[i]][i][i][y-1];
                  }
            }
            flag[v[i]]^=1;
            t-=d[i];
            stack[p--]=0;
          }
    }
    printf("%ld\n",f[flag[0]][0][0][m]);
}

