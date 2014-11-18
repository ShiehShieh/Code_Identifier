#include <iostream>
using namespace std;

int a[101],b[101][2];

int main()
{
    int n,i,j,maxn=0;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i][0]=b[i][1]=1;
    }
    for (i=2;i<=n;i++)
    {
        for (j=1;j<i;j++)
        {
            if (a[j]<a[i])
            {
               b[i][0]=max(b[i][0],b[j][0]+1);
            }
        }
    }
    for (i=n-1;i>=1;i--)
    {
        for (j=n;j>i;j--)
        {
            if (a[j]<a[i])
            {
               b[i][1]=max(b[i][1],b[j][1]+1);
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        if (b[i][0]+b[i][1]>maxn)
        {
           maxn=b[i][0]+b[i][1];
        }
    }
    cout<<n-maxn+1<<endl;
    return 0;
}

