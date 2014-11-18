/*  Vijos P1198  */
#include <iostream>
using namespace std;

long long n,m;
long long f[401][401];
long long v[401][401];

long long calc(long long a,long long b,long long j)
{
    long long re=1;
    for (   ;b>=1;b--)
       re*=j;
    return re*a;
}

void init()
{
     register long long a,b;
     cin>>n>>m;
     for (register long long i=1;i<=m;i++)
        {
              cin>>a>>b;
              for (register long long j=1;j<=n;j++)
                 v[i][j]=calc(a,b,j);
        }
     memset(f,-1,sizeof(f));
}

void dp()
{
     for (long long i=0;i<=n;i++)
       f[1][i]=v[1][i];
     for (register long long i=2;i<=m;i++)
       for (register long long j=1;j<=n;j++)
         for (register long long k=0;k<=j;k++)
           if (f[i][j]==-1)
              f[i][j]=f[i-1][j-k]+v[i][k];
           else
              f[i][j]=min(f[i][j],f[i-1][j-k]+v[i][k]);
}

void print()
{
     cout<<f[m][n]<<endl;
}

int main(void)
{
    init();
    dp();
    print();
    return 0;
}
