#include <iostream>
using namespace std;
int m=0, n=0, c[52][52]={0}, f[101][52][52]={0};
int y(int b, int x)
{
    return -x+b+1;
}
int main()
{
    cin>>m>>n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin>>c[i][j];
    int l=0, r=0;
    for (int i=1; i<m+n-1; i++)
    {
        l = i-m+1;
        r = l+m-1;
        if (l<1) l=1;
        if (r>n) r=n;
        for (int j=l; j<r; j++)//The first path
            for (int k=j+1; k<=r; k++)//The second path
            {
                f[i][j][k] = f[i-1][j-1][k-1];
                if (f[i-1][j][k] > f[i][j][k])
                    f[i][j][k] = f[i-1][j][k];
                if (f[i-1][j-1][k] > f[i][j][k])
                    f[i][j][k] = f[i-1][j-1][k];
                if (j != k-1)
                    if (f[i-1][j][k-1] > f[i][j][k])
                        f[i][j][k] = f[i-1][j][k-1];
                f[i][j][k] += c[y(i, j)][j]+c[y(i, k)][k];
            }
    }
    cout<<f[m+n-2][n-1][n];
    return 0;
}

