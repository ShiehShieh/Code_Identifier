#include<iostream>
#include<string>
using namespace std;
int main()
{
    string name[101];
    char ganbu[101],xibu[101];
    short n,qimo[101],pingyi[101],lunwen[101],i,maxi;
    long money[101],all=0;
    cin>>n;
    for(i=0;i<=n;i++) money[i]=0;
    for(i=1;i<=n;i++) cin>>name[i]>>qimo[i]>>pingyi[i]>>ganbu[i]>>xibu[i]>>lunwen[i];
    for(i=1;i<=n;i++)
    {
                     if((qimo[i]>80) && (lunwen[i]>=1))   money[i]=money[i]+8000;
                     if((qimo[i]>85) && (pingyi[i]>80))   money[i]=money[i]+4000;
                     if(qimo[i]>90)                       money[i]=money[i]+2000;
                     if((qimo[i]>85) && (xibu[i]=='Y'))    money[i]=money[i]+1000;
                     if((pingyi[i]>80) && (ganbu[i]=='Y')) money[i]=money[i]+850;
    }
    for(i=1;i<=n;i++) all=all+money[i];
    maxi=0;
    for(i=1;i<=n;i++) if(money[i]>money[maxi]) maxi=i;
    cout<<name[maxi]<<endl;
    cout<<money[maxi]<<endl;
    cout<<all<<endl;
    return 0;
}
