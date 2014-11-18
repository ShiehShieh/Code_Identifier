#include <iostream>
using namespace std;
const int M = 500;
int i,j,n,ok,v[110],u[110],w[110],now,k,m,can[110];
double t,T;
int main()
{
  cin >> n;
  for (i=1;i<=n;i++)
   scanf("%d%d%d",&v[i],&u[i],&w[i]);
  for (i=0;i<=M;i++)
   for (j=0;j<=M-i;j++)
   {
     now = 0;
     k = M-i-j;
     T = 1000000;
     for (m=1;m<=n;m++)
     {
       t = (double)i/v[m]+(double)j/u[m]+(double)k/w[m];
       if ( t<T )
       {
         now = m;
         T = t;
       }
       else if ( t==T ) now = 0;
     }
     can[now] = 1;
   }
  for (i=1;i<=n;i++)
   if ( can[i] ) printf("Yes\n");
   else printf("No\n");
  cin >> n;
  return 0;
}

