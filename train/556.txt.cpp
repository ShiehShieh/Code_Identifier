#include<iostream>
#include<algorithm>
using namespace std;
long findmax(long x,long y,long z)
{
    long p=x;
    if (p<y) p=y;
    if (p<z) p=z;
    return p;
}
int main()
{
    long n,sum;
    cin>>n;sum=0;
    long a[n+1];
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    long f[n+1][sum+1];
    for (int i=0;i<=n;i++)
      for (int j=0;j<=sum;j++)
        f[i][j]=-20000;
    f[0][0]=0;
    for (int i=1;i<=n;i++)
      for (int j=0;j<=sum;j++)
      {
            if (j>a[i]) f[i][j]=findmax(f[i-1][j],f[i-1][j+a[i]],f[i-1][j-a[i]]+a[i]);
            else f[i][j]=findmax(f[i-1][j],f[i-1][j+a[i]],f[i-1][a[i]-j]+j);
        }
    if (f[n][0]>0) cout<<f[n][0]<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}

