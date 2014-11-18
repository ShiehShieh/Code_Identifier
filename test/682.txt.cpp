#include<iostream>
using namespace std;
int a[10000],b[10000],c[10000],i,j,k,n;
int main()
{
    cin>>n;
    for (i=1;i<=n;i++) cin>>a[i];
    for (i=1;i<=n;i++)
    {
        b[i]=1;
        for (j=1;j<i;j++)
        if (a[j]<a[i]&&b[j]+1>b[i]) b[i]=b[j]+1;
    }
    for (i=n;i>=1;i--)
    {
        c[i]=1;
        for (j=n;j>i;j--)
        if (a[j]<a[i]&&c[j]+1>c[i])
        c[i]=c[j]+1;
    }
    int maxn=1;
    for (i=1;i<=n;i++)
    if (c[i]+b[i]>maxn)
    maxn=c[i]+b[i];
    cout<<n-maxn+1;
    return 0;
}

