/*  Vijos P1225  */

#include <iostream>
using namespace std;

const int INF=(-23860);

int m,n;
int d[301][301];
int sum[301];
int ans=(-1);

void init()
{
     cin>>m>>n;
     for (int i=1;i<=m;i++)
       for (int j=1;j<=n;j++)
         {
            scanf("%d",&d[i][j]);
            if (d[i][j]==0)
              d[i][j]=INF;
         }
}

int dp(int n)
{
    int tmp=0;
    int re=0;
    for(int i=1;i<=n;++i)
      {
         if(tmp>0)
           tmp=tmp+sum[i];
         else
           tmp=sum[i];
         if(tmp>re)
           re=tmp;
      }
    return re;
}

void work()
{
     int tmp;
     for (int i=1;i<=m;i++)
       {
          for (int j=1;j<=n;j++)
             sum[j]=0;
          for (int j=i;j<=m;j++)
             {
                for (int k=1;k<=n;k++)
                  sum[k]=sum[k]+d[j][k];
                tmp=dp(n);
                if (tmp>ans)
                  ans=tmp;
             }
       }
}

void print()
{
     cout<<ans<<endl;
}

int main(void)
{
    init();
    work();
    print();
    return 0;
}
