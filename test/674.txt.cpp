#include <iostream>
using namespace std;
int n=0, c, maxv=0;
bool f[20010] = {0};
int main()
{
    f[0] = true;
    cin>>maxv>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>c;
        for (int j=maxv; j>=0; j--)
            if (j-c>=0 && f[j-c])
                f[j] = true;
    }
    for (int i=maxv; i>=0; i--)
        if (f[i])
        {
            cout<<maxv-i;
            break;
        }
    return 0;
}

