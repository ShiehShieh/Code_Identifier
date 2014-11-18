#include <iostream>
#define lar 1000000000
using namespace std;
unsigned long arr[8];
void multiply2()
{
    unsigned long carry=0;
    int cur=0;
    do
    {
        arr[cur]=(arr[cur]*2+carry);
        carry=arr[cur]/lar;
        arr[cur]%=lar;
        cur++;
    }while(carry!=0||arr[cur]!=0);
}
void outputsin(int i)
{
    unsigned long temp=arr[i];
    int a[9],j=0;
    for(int k=0;k<9;k++)
    {
        a[k]=0;
    }
    while(temp!=0)
    {
        a[j++]=temp%10;
        temp/=10;
    }
    for(int k=8;k>=0;k--)
    {
        cout<<a[k];
    }
}
void output()
{
    int i;
    for(i=7;i>=0&&arr[i]==0;i--);
    cout<<arr[i--];
    for(;i>=0;i--)
    {
        outputsin(i);
    }
}
int main()
{
    int n;
    cin>>n;
    arr[0]=1;
    for(int i=0;i<n+1;i++)
    {
        multiply2();
    }
    arr[0]-=2;
    output();
    return 0;
}
