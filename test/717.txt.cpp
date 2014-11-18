#include <iostream>
using namespace std;
int main()
{
    int l,m,v1,v2,i,j,js=0;
    cin>>l>>m;
    bool a[l+1];
    for (i=0;i<=l;i++) a[i]=true;
    for (i=1;i<=m;i++)
    {
        cin>>v1>>v2;
        for (j=v1;j<=v2;j++) a[j]=false;
    }
    for (i=0;i<=l;i++) if (a[i]==true) js++;
    cout<<js;
    return 0;
}

