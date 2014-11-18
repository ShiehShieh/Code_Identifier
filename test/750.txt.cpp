#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i,a[1001],s,m;
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++){cin>>m;a[m]=m;}
    s=0;
    for(i=0;i<1001;i++)if(a[i]!=0)s++;
    cout<<s<<endl;
    for(i=0;i<1001;i++)if(a[i]!=0)cout<<a[i]<<' ' ;
    return 0;
}

