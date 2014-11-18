#include <iostream>
using namespace std;
double f[2][110],ans;
int i,j,n,m,c,now;
int main()
{
  while (scanf("%d%d%d",&c,&n,&m)!=EOF)
  {
    if ( c==0 ) break;
	if ( m>c || n%2!=m%2 )
    {
      printf("0.000\n");
      continue;
    }
    if ( n==0 && m==0 )
    {
      printf("1.000\n");
      continue;
    }
    if ( n<=5000 )
    {
      for (i=0;i<=c;i++)
       f[0][i] = f[1][i] = 0;
      now = 0;
      f[now][0] = 1;
      for (i=1;i<=n;i++)
      {
        now = !now;
        for (j=0;j<=c;j++)
        {
          f[now][j] = 0;
          if ( j>0 ) f[now][j] += (f[!now][j-1]*(c-j+1))/c;
          if ( j<c ) f[now][j] += (f[!now][j+1]*(j+1))/c;
        }
      }
      printf("%.3lf\n",f[now][m]);
      continue;
    }
    ans = 2;
    for (i=1;i<=m;i++)
     ans = (ans*(c-i+1))/i;
    for (i=1;i<=c;i++)
     ans /= 2;
    printf("%.3lf\n",ans);
  }
  return 0;
}

