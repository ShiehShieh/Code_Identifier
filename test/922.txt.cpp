#include<iostream>
using namespace std;
int main()
{
    int i=1,c=0,a[13],b[13];
    b[0]=0;a[0]=0;
   
    while(i<=12)
    {cin>>a[i];b[i]=300+b[i-1]-a[i];
    if(b[i]<0)break;
    if(b[i]>=100){c+=b[i]-(b[i]%100);b[i]%=100;}
    i++;
    }
    if(i<13)cout<<-i<<endl;
    if(i==13)cout<<b[12]+c+c/5<<endl;

    return(0);
    
}
