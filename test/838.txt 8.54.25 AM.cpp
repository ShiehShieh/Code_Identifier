#include <iostream>
using namespace std;
int main()
{
    int a[13];
    int js=0,sum=0,i;
    a[0]=0;
    for(i=1;i<=12;i++)
    {
                     cin>>a[i];
                     a[i]=300-a[i];
                     a[i]=a[i-1]+a[i];
                     if(a[i]<0)
                     {
                               cout<<"-"<<i<<endl;
                               return 0;
                     }
                     if(a[i]>=100&&a[i]<200)
                     {
                                             js++;
                                             a[i]=a[i]-100;
                     }
                     if(a[i]>=200&&a[i]<300)
                     {
                                            js=js+2;
                                            a[i]=a[i]-200;
                     }
                     if(a[i]>=300&&a[i]<400)
                     {
                                            js=js+3;
                                            a[i]=a[i]-300;
                     }
    }
    js=js*120;
    sum=js+a[12];
    cout<<sum<<endl;
    return 0;
}

