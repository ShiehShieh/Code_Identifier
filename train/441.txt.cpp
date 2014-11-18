#include <iostream>
#include <string.h>
using namespace std;
int n=0, c[102]={0}, t=0, sum=0, minsum=0;
bool f[10002]={0}, tot[10002]={0};
int main()
{
    cin>>n;
    tot[0] = true;
    while (true)
    {
          t++;
          cin>>c[t];
          if (c[t] == -1) break;
          sum += c[t];
          for (int j=sum; j>=0; j--)
              if (j-c[t] >= 0) if (tot[j-c[t]])
                  tot[j] = true;
    }
    minsum = sum;
    for (int i=1; i<n; i++)
    {
        t = 0;
        sum = 0;
        memset(f, 0, sizeof(f));
        f[0] = true;
        while (true)
        {
            t++;
            cin>>c[t];
            if (c[t] == -1) 
            {
                if (sum < minsum) minsum = sum;
                break;
            }
            sum += c[t];
            for (int j=sum; j>=1; j--)
                if (j-c[t] >= 0) if (f[j-c[t]])
                    f[j] = true;
        }
        for (int j=1; j<=sum; j++)
            tot[j] &= f[j];
    }
    for (int i=minsum; i>=0; i--)
        if (tot[i])
        {
            cout<<i;
            break;
        }
    return 0;
}

