#include <iostream>
using namespace std;
int n,m,i,M,j,x,ok,b[3010],a[3010],f[5000010];
int main()
{
  cin >> n >> m;
  for (i=1;i<=n;i++)
  {
    scanf("%d",&x);
    for (j=0;j<=m && j<x;j++)
     a[x-j] = 1;
  }
  m = 0;
  for (i=1;i<=3000;i++)
   if ( a[i] )
    b[++m] = i;
  for (i=2;i<=b[1];i++)
  {
    ok = m;
    for (j=1;j<=m;j++)
     if ( b[j]%i==0 )
      ok--;
    if ( ok==0 )
    {
      cout << -1 << endl;
      return 0;
    }
  }
  M = 20000000/m;
  f[0] = 1;
  for (i=1;i<=m;i++)
   for (j=b[i];j<=M;j++)
    if ( f[j-b[i]] ) 
     f[j] = 1;
  for (i=M;i>0 && f[i];i--);
  if ( i==0 ) i--;
  cout << i << endl;
  return 0;
}
