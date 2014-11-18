#include<iostream>
#include<cmath>
using namespace std;
short f[2501],g[2501],i,j,n,d;
char ch;
int main(){
    cin>>n>>d;
    for(i=1;i<=n;i++)
    {
                     cin>>ch;
                     if(ch=='H')g[i]=g[i-1]+1;
                     else g[i]=g[i-1]-1;
    }
    for(i=1;i<=n;i++)
    {
                     f[i]=32767;
                     for(j=0;j<=i-1;j++)
                     if((f[j]<f[i])&&((abs(g[i]-g[j])<=d)||(abs(g[i]-g[j])==abs(i-j))))
                     f[i]=f[j]+1;
                     }
                     cout<<f[n];
    }

