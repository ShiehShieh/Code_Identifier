#include <iostream>
using namespace std;
#define MAXN 101
short f[MAXN][MAXN * MAXN], ans[MAXN * MAXN];
int main(){
    short n, w[MAXN][MAXN], h, b[MAXN], i, j, k, min_h = 20000;
    cin>>n;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1, h = 0; cin>>k && -1 != k; ++j)
        {
            w[i][j] = k;
            h += k;
        }
        b[i] = j - 1;
        if (min_h > h)
            min_h = h;
    }
    for (k = 1; k <= n; ++k)
    {
        memset(f, 0, sizeof(f));
        for (i = 1; i <= b[k]; ++i)
        {
            f[i][0] = 0;
            f[i][w[k][i]] = 1;
        }
        for (i = 2; i <= b[k]; ++i)
        {
            for (j = 1; j <= min_h; ++j)
            {
                if (f[i - 1][j] || (j > w[k][i] && f[i - 1][j - w[k][i]]))
                    f[i][j] = 1;
            }
        }
        for (j = 1; j <= min_h; ++j)
        {
            if (f[b[k]][j])
                ++ans[j];
        }
    }
    for (j = min_h; j > 0; --j)
    {
        if (ans[j] == n)
        {
            cout<<j;
            break;
        }
    }
    if (!j)
        cout<<"0";}
