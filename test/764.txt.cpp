#include <iostream>
using namespace std;
int main()
{
    int i,js=0,n;
    int a[10];
    for(i=0;i<10;i++)
    {
                     cin>>a[i];
    }
    cin>>n;
    n=n+30;
    for(i=0;i<10;i++)
    {
                    if(a[i]<=n)
                    js++;
    }
    cout<<js;
    return 0;
}
