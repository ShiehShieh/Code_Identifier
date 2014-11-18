#include <iostream>
using namespace std;
int n=0, c[102]={0};
bool f[2002][2002] = {0};
int sum = 0;
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>c[i];
        sum += c[i];
    }
    f[0][0] = true;
    for (int i=1; i<=n; i++)
        for (int j=sum/2; j>=0; j--)
            for (int k=j; k>=0; k--)
            {
                if (f[j][k]) continue;
                if (j-c[i]>=0)
                {
                    if (j-c[i]>=k)
                    {
                        if (f[j-c[i]][k])
                            f[j][k] = true;
                    }
                    else
                    {
                        if (f[k][j-c[i]])
                            f[j][k] = true;
                    }
                }
                if (k-c[i]>=0)
                    if (f[j][k-c[i]])
                        f[j][k] = true;
            }
    for (int i=sum/2; i>=1; i--)
       if (f[i][i])
       {
           cout<<i;
           exit(0);
       }
    cout<<"Impossible";
    return 0;
}

