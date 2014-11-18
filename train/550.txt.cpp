#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long n,tsum;
    cin>>n;cin>>tsum;
    long f[n+1][tsum+1],happy[n+1],time[n+1];
    for (int i=1;i<=n;i++) cin>>happy[i]>>time[i];
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
      for (int j=1;j<=tsum;j++)
      {
            f[i][j]=f[i-1][j];
            if (j>=time[i])
              if (f[i-1][j-time[i]]+happy[i]>f[i][j])
                f[i][j]=f[i-1][j-time[i]]+happy[i];
        }
    cout<<f[n][tsum]<<endl;
    return 0;
}

