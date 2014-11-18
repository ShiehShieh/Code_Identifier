#include<iostream>
using namespace std;
int main()
{
    int a[11],s=0;
    for (int i=1;i<=10;i++)
        cin>>a[i];
    int n;
    cin>>n;
    for (int i=1;i<=10;i++)
    if (n+30>=a[i])s++;
    cout<<s<<endl;    
    return 0;
}

