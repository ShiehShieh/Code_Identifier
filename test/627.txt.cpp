#include <iostream>
#include <cstring>
using namespace std;
int f[101000] = { 0 }, f1[101000] = { 0 }, o[101000] = { 0 };
int main()
{
    int n, v, w[101], i, j, left[101] = { 0 };

    cin>>v>>n;
    for (i = 1; i <= n; ++i)
    cin>>w[i];
    f[0] = 1;
    for (i = 1; i <= n; ++i)
    {
        memcpy(f1, f, sizeof(f));
        for (j = w[i]; j <= v; ++j)
        {
            if (f[j - w[i]])
            {
                ++f1[j];
                if (0 == o[j])
                    o[j] = i;
            }
        }
        memcpy(f, f1, sizeof(f));
        if (f[v] > 1)
            break;
    }

    if (0 == f[v])
        cout<<"0";
    else if (2 == f[v])
        cout<<"-1";
    else // 1 == f[v]
    {
        for (j = v; j; j -= w[o[j]])
            left[o[j]] = 1;
        for (i = 1; i <= n; ++i)
            if (!left[i])
                cout<<i<<" ";
    }
}

