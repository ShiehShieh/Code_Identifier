#include <iostream>
using namespace std;

int a[31][20001],w[31];

int main()
{
    memset (a,0,sizeof (a)); 
    int n,m,i,j;
    cin>>m>>n;
    for (i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            a[i][j]=a[i-1][j];
            if (w[i]<=j&&a[i-1][j-w[i]]+w[i]>a[i][j])
            {
               a[i][j]=a[i-1][j-w[i]]+w[i];
            }
        }
    }
    cout<<m-a[n][m]<<endl;
    return 0;
} 

