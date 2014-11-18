#include<iostream>
using namespace std;
long long m=1,n;
int main(){
    cin>>n;
    while(1)
    {
       if((m<n)&&(m*9>n)){cout<<"181818181818";return 0;}
       m*=9;
       if((m<n)&&(m*2>n)){cout<<"ZBT";return 0;}
       m*=2;
    }
}

