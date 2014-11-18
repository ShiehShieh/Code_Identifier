#include<iostream>
using namespace std;
short n, i, a, b;
unsigned long long k1=1,k2=1;
int main(){
    cin>>n>>a>>b;
    for(i=1;i<=a;i++)
    k1=(long long)(k1*(n+i)/i);
    for(i=1;i<=b;i++)
    k2=(long long)(k2*(n+i)/i);
    cout<<k1*k2;}
