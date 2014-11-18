#include<iostream>
using namespace std;
int fun(int n,int k,int start)
{
    int i=start,sum=0;
    if(k==1) return 1;
    for(;i<=n/k;i++)
    sum+=fun(n-i,k-1,i);
    return sum;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<fun(n,k,1);
    return 0;
}

