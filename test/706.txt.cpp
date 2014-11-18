#include <iostream>
using namespace std;

int main()
{
    int n,i,p=0,c,j=0;
    cin>>n;
    int a[10000];
    for (i=1;i<=n;i++) 
    {
        cin>>a[i];
        p+=a[i];
    }
    p=p/n;
    for (i=1;i<=n;i++)
        if (a[i]!=p)
        {
            c=p-a[i];
            a[i]=a[i]+c;
            a[i+1]=a[i+1]-c;
            j++;
        }
    cout<<j<<endl;
    return 0;
}
