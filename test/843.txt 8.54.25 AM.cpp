#include<iostream>
using namespace std;
int main()
{
    int n,k,q,s=0,z=0;
    cin>>k>>n;
    int h[201]={},a[n+1];
    for (int i=1;i<=n;i++)
    {
    cin>>q;
    h[q]++;
    }
    for (int i=1;i<=200;i++)
        for (int j=1;j<=h[i];j++)
        {
            s++;
            a[s]=i;
        }
    int i=1,j=s;
    while (i<j)
    {
        if (a[j]+a[i]<=k)
            i++;
        z++;
        j--;
    }
    if (i==j)z++;
    cout<<z<<endl;
    return 0;
}

