#include<iostream>
using namespace std;
int main(){
    unsigned long a,b,c;
    cin>>a;
    b=a<<16;
    c=a>>16;
    a=b+c;
    cout<<a;
    return 0;
}
