#include <cstdio>
#include <cstring>
#include <cstdlib>
#define maxm 100010
#define maxn 6
#define maxint 21474836
#define minab(a,b) (a)<(b) ?(a) :(b)

typedef struct node
{int x,pos;
}node;
node q[maxn][maxm];

int f[maxn][maxm],ff[maxn][maxm],sum[maxn][maxm];
int m,n,kk,l,head[maxn],tail[maxn];

void ini(void)
{
 memset(sum,0,sizeof(sum));
 int t,i,j;
 scanf("%d%d%d%d",&m,&n,&kk,&l);
 for (i=1;i<=n;i++)
   for (j=1;j<=m;j++)
     {
      scanf("%d",&t);
      sum[i][j]=sum[i][j-1]+t;
     }
}

void insert(int x,int pos,int num)
{
 while ( (head[num]<=tail[num]) && ( ! ( q[num][tail[num]].x < x ) ) )
   --tail[num];
 ++tail[num];
 q[num][tail[num]].x=x;
 q[num][tail[num]].pos=pos;
}

void del(int pos,int num)
{
 while ( (head[num]<=tail[num]) && ( q[num][head[num]].pos < pos ) )
   ++head[num];
}

void work(void)
{
 int i,j,p,min;
 //  head、tail 的初值 
 for (i=1;i<=n;i++)
   {
    head[i]=1;
    tail[i]=0;
   }
 //  单调队列 和 dp 的初值
 for (i=1;i<=n;i++)
   {
    f[i][0]=-kk;
    ff[i][0]=-kk;
    insert(ff[i][0],0,i);
   }
 // dp
 for (j=1;j<=m;j++)
   {
    for (p=1;p<=n;p++)
      f[p][j]=q[p][head[p]].x+sum[p][j]+kk;
    for (i=1;i<=n;i++)
      {
       min=maxint;
       for (p=1;p<=n;p++)
         if (p!=i)
           if (f[p][j]<min)
             min=f[p][j];
       ff[i][j]=min;
       insert(ff[i][j]-sum[i][j],j,i);
       del(j-l+1,i);
      }
   }
}

void pr(void)
{
 int i, ans = maxint ;
 for (i=1;i<=n;i++)
   {
    if (f[i][m]<ans)  ans=f[i][m];
   }
 printf("%d\n",ans);
}

int main()
{ini();
 work();
 pr();
 return(0);
}

