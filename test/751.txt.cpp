#include<iostream>
using namespace std;
int main()
{
int n,i=0;
cin>>n;
while(n-i>1)
n-=++i;
if(i%2==1)cout<<n<<'/'<<i-n+2<<endl;else cout<<i-n+2<<'/'<<n<<endl;
return 0;
} 
