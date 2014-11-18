#include <iostream>
using namespace std;
long long i,j,n,hi,lo,x,len[1010],mag[1010],f[1010][1010];
int main()
{
  cin >> n >> lo >> hi;
  for (i=1;i<=n;i++)
  {
    scanf("%I64d",&x);
    len[i] = len[i-1]+x;
  }
  for (i=1;i<=n;i++)
  {
    scanf("%I64d",&x);
    mag[i] = mag[i-1]+x;
  }
  for (i=1;i<=n;i++)
   for (j=i;j<=n;j++)
   {
     f[i][j] = max(f[i-1][j],f[i][j-1]);
     if ( len[j]-len[i-1]>=lo && len[j]-len[i-1]<=hi )
      f[i][j] = max(f[i][j],f[i-1][j-1]+mag[j]-mag[i-1]);
   }
  cout << f[n][n] << endl;
  return 0;
}
