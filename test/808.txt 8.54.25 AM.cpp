#include <iostream>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    long long s=0;
    while(n>0){
                 s+=n*n;
                 n--;
                 }
    cout<<s;
    return 0;
}
