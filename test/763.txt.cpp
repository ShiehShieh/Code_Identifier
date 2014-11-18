#include <iostream>
using namespace std;
int main()
{
    double k,n=0,s,he=0;
    cin>>k;
    while(he<=k)
    {
               n++;
               s=1/n;
               he+=s;
    }
    cout<<n;
    return 0;
}

