#include <iostream>
using namespace std;
int main()
{
    int n,i,j,s,k,l;
    cin>>n;
    int a[n+1];
    k=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        k=k+a[i];
    }
    k=k/n;
    s=0;
    l=0;
    for(i=1;i<=n;i++)
       a[i]=a[i]-k;
    for(i=1;i<=n;i++)
    {
        s=s+a[i];
        if(s!=0)
        l=l+1;
    }
    cout<<l;
    return 0;
}
