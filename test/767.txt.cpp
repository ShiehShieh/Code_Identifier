#include <iostream>
using namespace std ;
int main()
{   const unsigned long long MAX = 65536; //MAX = 2^16 
    unsigned long long dest, high, low,n;
    cin>>n;  
    low=n%MAX; //取低16位数 
     high=n-low;//取高16位数 
     dest=low*MAX;//将低16位数左移16位，即乘以2^16
    dest+=high/MAX;//将高16位数右移16位，即除以2^16    
    cout<<dest; 
}
