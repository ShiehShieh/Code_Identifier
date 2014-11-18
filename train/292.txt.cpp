#include<iostream>
using namespace std;
int main()
{
    bool num[1001];
    int x,n,i,counter=0;
    for (i=0;i<1001;i++)
    {
        num[i]=false; 
    } 
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>x;
        num[x]=true; 
    }
    for (i=0;i<1001;i++)
    {
        if (num[i]!=0)
        {
           counter++; 
        } 
    }
    cout<<counter<<endl;
    for (i=0;i<1001;i++)
    {
        if (num[i]!=0)
        {
           cout<<i<<' '; 
        } 
    } 
    return 0; 
} 

