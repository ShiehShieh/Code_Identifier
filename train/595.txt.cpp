#include <iostream>
using namespace std;
int f1[1000],f2[1000],n,a[1000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        f1[i]=1;
        for(int j=1;j<i;j++){
            if(a[i]>a[j]&&f1[i]<f1[j]+1)
                f1[i]=f1[j]+1;
        }
    }
    for(int i=n;i>=1;i--){
        f2[i]=1;
        for(int j=n;j>i;j--){
            if(a[i]>a[j]&&f2[i]<f2[j]+1)
                f2[i]=f2[j]+1;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(sum<f1[i]+f2[i])
            sum=f1[i]+f2[i];
    }
    cout<<n-sum+1<<endl;
    return 0;
}
