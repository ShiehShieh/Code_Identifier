#include<iostream>
using namespace std;
int f(int x)
{if(x==0)return 0;
    return x^f(x/2);
}
int main()
{
    int n;
    cin>>n;
    cout<<f(n)+1;
    return 0;
}

