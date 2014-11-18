#include <iostream>
using namespace std;
int n,inc,i,l;
long long ans,a,MAXN,f,m;
int main()
{
  cin >> n >> m;
  MAXN = (long long)181818*1000000+181818;
  if ( n==1 ) ans = 0;
  else if ( n==2 )
  {
    if ( m==1 ) ans = 1;
    else ans = -18;
  }
  else
  {
    a = ans = f = 1;
    m--;
    inc = n-3;
    for (;m>0;)
    {
      f = min(f+inc,m);
      m -= f;
      a = (a*2)%MAXN;
      ans  = (ans+a*f)%MAXN;
    }
  }
  cout << ans << endl;
  cin >> n;
  return 0;
}

