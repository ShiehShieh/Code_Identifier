#include <iostream>
using namespace std;
int f[30000];
int a[31];
int n,t;
int main()
{
    cin>>t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=t;j>=a[i];j--){
            f[j]=max(f[j],f[j-a[i]]+a[i]);
        }
    }
    int ans=0;
    for(int i=t;i>=0;i--){
        if(ans<f[i]) ans=f[i];
    }
    cout<<t-ans<<endl;
    return 0;
}
