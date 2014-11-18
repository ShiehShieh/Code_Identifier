#include<iostream>
using namespace std;

int main()
{
    int N=0,a[1001]={0};
    cin>>N;
    a[1]=1;
    for(int i=2;i<=N;i++)
    {
        a[i]=a[i-1]+((i+1)%2)*a[i/2];
    }
    cout<<a[N]<<endl;
    return 0;
}
