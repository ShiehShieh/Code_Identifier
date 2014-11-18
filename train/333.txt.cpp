#include <iostream>
using namespace std;
int n=0, m=0, f[1002][1002]={0}, totmax=0;
int getmin(int x, int y, int z)
{
    int rt = x<y?x:y;
    if (z<rt) rt=z;
    return rt;
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin>>f[i][j];
            if (f[i][j] !=0)
            {
                f[i][j] = getmin(f[i-1][j-1], f[i][j-1], f[i-1][j])+1;
                if (f[i][j] > totmax) totmax=f[i][j];
            }
        }
    cout<<totmax;
    return 0;
}

