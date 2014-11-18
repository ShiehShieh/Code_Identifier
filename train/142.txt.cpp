#include<iostream>
using namespace std;
int main()
{
    short a[8][3],b[8],i,max=0,mi=1;
    for(i=1;i<=7;i++) cin>>a[i][1]>>a[i][2];
    for(i=1;i<=7;i++) b[i]=0;
    for(i=1;i<=7;i++) if(a[i][1]+a[i][2]>8) b[i]=a[i][1]+a[i][2]-8;
    for(i=1;i<=7;i++) 
    {
                      if(b[i]>max) 
                      {
                                   max=b[i];
                                   mi=i;
                      }
    }
    cout<<mi<<endl;
    cin>>i;
    return 0;
}  
