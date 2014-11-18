#include <iostream>
using namespace std;
int n=0, f[210][210]={0}, maxf=0;
bool map[210][210]={0};
int getmin(int x, int y)
{
    return x<y?x:y;
}
int main()
{
    cin>>n;
    char ch = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=(n-i)*2+1;)
        {
            cin>>ch;
            if (ch == '#')
                j++;
            if (ch == '-')
            {
                map[i][j] = true;
                j++;
            }
        }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=(n-i)*2+1; j+=2)
        {
            if (map[i][j])
            {
                if (map[i-1][j+1])
                    f[i][j] = getmin(f[i-1][j], f[i-1][j+2])+1;
                else
                    f[i][j] = 1;
                if (f[i][j] > maxf) maxf = f[i][j];
            }
        }
    for (int i=n; i>=1; i--)
        for (int j=2; j<(n-j)*2+1; j+=2)
        {
            if (map[i][j])
            {
                if (map[i+1][j-1])
                    f[i][j] = getmin(f[i+1][j-2], f[i+1][j])+1;
                else
                    f[i][j] = 1;
                if (f[i][j] > maxf) maxf = f[i][j];
            }
        }
    cout<<maxf*maxf;
    return 0;
}
