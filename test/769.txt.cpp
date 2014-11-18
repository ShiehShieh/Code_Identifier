#include <iostream>
using namespace std;
int sum[2001][2001]={0},f[2001][2001]={0};
int main()
{   int a[2001],n;
    bool flag;
    cin>>n;
    cin>>flag;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
       {sum[i][i]=f[i][i]=a[i];
        for (int j=i+1;j<=n;j++)
            sum[i][j]=sum[i][j-1]+a[j];
       }
    for (int l=1;l<n;l++)
        for (int i=1;i<=n-l;i++)
            f[i][i+l]=sum[i][i+l]-min(f[i][i+l-1],f[i+1][i+l]);
    if(flag)cout<<f[1][n];
    else    cout<<sum[1][n]-f[1][n];
}

