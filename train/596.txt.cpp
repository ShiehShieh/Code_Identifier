#include <iostream>
using namespace std;
struct {bool val; int last, card;}f[100002];
int tot=0, n=0, w[102]={0}, sign[102]={0};
int main()
{
    cin>>tot>>n;
    for (int i=1; i<=n; i++) cin>>w[i];
    f[0].val = true;
    for (int i=1; i<=n; i++)
    {
        for (int j=tot; j>=0; j--)
        {
            if (!f[j].val || j==tot)
            if (j-w[i]>=0) if (f[j-w[i]].val)
            {
               if (j == tot && f[j].val)
               {
                   cout<<-1;
                   exit(0);
               }
               f[j].val = true;
               f[j].last = j-w[i];
               f[j].card = i;
            }
        }
    }
    if (!f[tot].val)
    {
        cout<<0;
        exit(0);
    }
    else
    {
        for (int i=tot; i>0;)
        {
            sign[f[i].card] = true;
            i = f[i].last;
        }
        int last = 0;
        for (int i=1; i<=n; i++)
            if (!sign[i]) last=i;
        for (int i=1; i<last; i++)
            if (!sign[i]) cout<<i<<' ';
        cout<<last;
    }
    return 0;
}

