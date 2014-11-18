#include <iostream>
using namespace std;

int main()
{
    int a[101][1001]={0},v[101],w[101],i,j,t,m;
    cin>>t>>m;
    for (i=1;i<=m;i++)
    {
        cin>>v[i]>>w[i];
    }
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=t;j++)
        {
            if (v[i]<=j&&a[i-1][j-v[i]]+w[i]>a[i-1][j])
            {
               a[i][j]=a[i-1][j-v[i]]+w[i];
            }
            else
            {
                a[i][j]=a[i-1][j];
            }
        }
    }
    cout<<a[m][t];
    return 0;
} 

