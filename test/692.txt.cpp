#include <iostream>
using namespace std;
int m=0, n=0, w[110][510]={0}, path[60000]={0}, pp=0;
long long b[110][510]={0}, f[110][510]={0};
int main()
{
    cin>>m>>n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        {
            cin>>b[i][j];
            f[i][j] = 1000000000000000ll;
        }
    for (int i=1; i<=n; i++)
        f[1][i] = b[1][i];
    for (int i=1; i<=m; i++)
    {
        int key = false;
        while (!key)
        {
            key = true;
            for (int j=1; j<=n; j++)
            {
                if (f[i-1][j]+b[i][j] < f[i][j])
                {
                    f[i][j] = f[i-1][j]+b[i][j];
                    w[i][j] = 1;
                    key = false;
                }
                if (j>1 && f[i][j-1]+b[i][j] < f[i][j])
                {
                    f[i][j] = f[i][j-1]+b[i][j];
                    w[i][j] = 2;
                    key = false;
                }
                if (j<n && f[i][j+1]+b[i][j] < f[i][j])
                {
                    f[i][j] = f[i][j+1]+b[i][j];
                    w[i][j] = 3;
                    key = false;
                }
        }
        }
    }
    long long mincost=1000000000000000ll;
    int minroom=0;
    for (int i=1; i<=n; i++)
        if (f[m][i] < mincost)
        {
            mincost = f[m][i];
            minroom = i;
        }
    for (int i=m; i>=1;)
    {
        pp++;
        path[pp] = minroom;
        if (i==1) break;
        if (w[i][minroom] == 1)
            {i--;continue;}
        if (w[i][minroom] == 2)
            {minroom --;continue;}
        if (w[i][minroom] == 3)
            {minroom ++;continue;}
    }
    for (int i=pp; i>=1; i--)
        cout<<path[i]<<endl;
    return 0;
}

