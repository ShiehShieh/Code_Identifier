#include <iostream>
using namespace std;

int a[401][401],v[51],m[51],w[51];

int main()
{
    int n,V,M,i,j,k,s=0;
    cin>>V>>M>>n;
    for (i=1;i<=n;i++)
    {
        cin>>v[i]>>m[i]>>w[i];
    }
    memset (a,0,sizeof (a));
    for (i=1;i<=n;i++)
    {
        for (j=V;j>=v[i];j--)
        {
            for (k=M;k>=m[i];k--)
            {
                a[j][k]=max (a[j][k],a[j-v[i]][k-m[i]]+w[i]);
                s=max (s,a[j][k]);
            }
        }
    }
    cout<<s<<endl;
    return 0;
}

