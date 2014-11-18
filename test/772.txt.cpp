#include <iostream>
using namespace std;
int fx(int m)
{
    if (m==0)
    return 0;
    else
    return
    m^fx(m/2);
}
int main()
{
    int n;
    cin>>n;
    cout<<fx(n)+1;
}
