#include <iostream>
using namespace std;

int main()
{
    int a[11],js=0,i,g;
    for (i=1;i<=10;i++) cin>>a[i];
    cin>>g;
    g+=30;
    for (i=1;i<=10;i++) if(g>=a[i]) js++;
    cout<<js;
    return 0;
}
