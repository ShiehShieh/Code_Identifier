#include<iostream>
using namespace std;
int main()
{
    int l,n,s=0;
    cin>>l>>n;
    int a[10001]={},c,d;
    for (int i=1;i<=n;i++)
    {
        cin>>c>>d;
        for (int j=c;j<=d;j++)
            a[j]=1;
    }
    for (int i=0;i<=l;i++)
    if (a[i]==0)s++;
    cout<<s<<endl;
    return 0;
}
