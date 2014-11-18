#include <iostream>
using namespace std;
int n=0, c[22][22]={0}, f[41][22][22][22]={0};
int y(int b, int x)
{
    return -x+b+1;
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin>>c[i][j];
    int l=0, r=0;
    f[1][1][1][1] = c[1][1];
    for (int i=2; i<=n+n-1; i++)
    {
        l = i-n+1;
        r = l+n-1;
        if (l<1) l=1;
        if (r>n) r=n;
        for (int l1=l; l1<=r; l1++)//The first path
            for (int l2=l1; l2<=r; l2++)//The second path
                for (int l3=l2; l3<=r; l3++)
                {
                    f[i][l1][l2][l3] = f[i-1][l1-1][l2-1][l3-1];
                    if (f[i-1][l1-1][l2-1][l3] > f[i][l1][l2][l3])
                        f[i][l1][l2][l3] = f[i-1][l1-1][l2-1][l3];
                    if (f[i-1][l1-1][l2][l3-1] > f[i][l1][l2][l3])
                        f[i][l1][l2][l3] = f[i-1][l1-1][l2][l3-1];
                    if (f[i-1][l1-1][l2][l3] > f[i][l1][l2][l3])
                        f[i][l1][l2][l3] = f[i-1][l1-1][l2][l3];
                    if (f[i-1][l1][l2-1][l3-1] > f[i][l1][l2][l3])
                        f[i][l1][l2][l3] = f[i-1][l1][l2-1][l3-1];
                    if (f[i-1][l1][l2-1][l3] > f[i][l1][l2][l3])
                        f[i][l1][l2][l3] = f[i-1][l1][l2-1][l3];
                    if (f[i-1][l1][l2][l3-1] > f[i][l1][l2][l3])
                        f[i][l1][l2][l3] = f[i-1][l1][l2][l3-1];
                    if (f[i-1][l1][l2][l3] > f[i][l1][l2][l3])
                        f[i][l1][l2][l3] = f[i-1][l1][l2][l3];
                    f[i][l1][l2][l3] += c[l1][y(i, l1)]+
                                        c[l2][y(i, l2)]+
                                        c[l3][y(i, l3)];
                    if (l1 == l2) f[i][l1][l2][l3] -= c[l1][y(i, l1)];
                    if (l2 == l3) f[i][l1][l2][l3] -= c[l2][y(i, l2)];
                }
    }
    cout<<f[n+n-1][n][n][n];
    return 0;
}

