#include <iostream>
using namespace std;
int a[1001][1001],n,m;
int f[1001][1001];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i][j]){
                f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
                if(ans<f[i][j]) ans=f[i][j];
            }
        }
    cout<<ans<<endl;
    return 0;
}
