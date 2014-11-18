#include <iostream>
using namespace std;
struct {int val, last; long long num;}f[100]={0};
int s[100] = {0}, p_s=0, sign[100] = {0};
long long pow10(int x)
{
    long long pro = 1;
    for (int i=1; i<=x; i++)
       pro *= 10;
    return pro;
}
int main()
{
    char ch = 0;
    while (cin>>ch)
    {
        p_s++;
        s[p_s] = ch-48;
    }
    for (int i=1; i<=p_s; i++)
    {
        long long inc=0;
        for (int j=i; j>=1; j--)
        {
            inc += s[j]*pow10(i-j);
            if (inc>f[j-1].num)
            {
                if (f[j-1].val+1>f[i].val)
                {
                    f[i].val = f[j-1].val+1;
                    f[i].num = inc;
                    f[i].last = j-1;
                }
                else
                    break;
            }
        }
    }
    for (int i=p_s; i>=1; i)
    {
        sign[f[i].last] = true;
        i = f[i].last;
    }
    for (int i=1; i<=p_s; i++)
    {
        cout<<s[i];
        if (sign[i]) cout<<',';
    }
    return 0;
}

