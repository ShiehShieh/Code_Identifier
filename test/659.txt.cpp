#include <iostream>
using namespace std;
struct st{int s, b;long long c;}cc[1002]={0};
int n0=0, s0=0, b0=0;
long long f[210][210];
int main()
{
    cin>>n0>>s0>>b0;
    long long si=0, bi=0, ci=0;
    for (int i=1; i<=n0; i++)
    {
        cin>>si>>bi>>ci;
        cc[i] = (st){si, bi, ci};
    }
    for (int i=0; i<100; i++)
        for (int j=0; j<100; j++)
           f[i][j] = 1000000000000000ll;
    f[0][0] = 0;
    for (int i=1; i<=n0; i++)
        for (int j=200; j>=0; j--)
            for (int k=200; k>=0; k--)
            {
                int m1=j-cc[i].s, m2=k-cc[i].b;
                if (m1<0) m1=0; if (m2<0) m2=0;
                if (f[m1][m2]+cc[i].c < f[j][k])
                    f[j][k] = f[m1][m2]+cc[i].c;
            }
    cout<<f[s0][b0]*2;
    return 0;
}

