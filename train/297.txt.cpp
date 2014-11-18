#include <iostream>
using namespace std;
int main()
{
    int d,e=0,i,j,m,n; 
    int a[1001]={0}; 
    cin>>n;
    for(i=1;i<=n;i++)
    {
                     cin>>j;
                     a[j]=1; 
    } 
    for(i=1;i<=1000;i++)
    {
                     if(a[i]!=0)e++; 
    } 
    cout<<e<<endl; 
    for(i=1;i<=1000;i++)
    {
                     if(a[i]!=0)
                     {
                                cout<<i;
                                if(i!=n)cout<<' '; 
                     }
    } 
    return 0; 
} 

