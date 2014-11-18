#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    const double pi=3.1415;
    int n,i;
    double r,l;
    cin >> n >> r;
    double a[n],b[n];
    for (i=0;i<=n-1;i++)
    cin >> a[i] >> b[i];
    l=pi*r*2;
    if (n==1)
    cout << (pi*r*2);
    else 
    {
         if (n==2)
         cout << (pi*r*2+2*sqrt((a[0]-a[1])* (a[0]-a[1])+(b[0]-b[1])*(b[0]-b[1])));
         else
         {
             for (i=0;i<=n-2;i++)
             l=l+sqrt((a[i+1]-a[i])*(a[i+1]-a[i])+(b[i+1]-b[i])*(b[i+1]-b[i]));
             l=l+sqrt((a[0]-a[n-1])*(a[0]-a[n-1])+(b[0]-b[n-1])*(b[0]-b[n-1]));
             cout << l;
             }
             }
             char t;
             cin >> t;
             return 0;
             }
