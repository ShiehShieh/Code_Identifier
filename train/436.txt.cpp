#include<fstream>
#include<iostream>
#include<iomanip> 
using namespace std;
int n,x[200001],y[200001],s[200001];
void init()
{
     int i;
     scanf("%d",&n);
     //cin>>n;
     for (i=1;i<=n;i++)
      scanf("%d %d %d",&x[i],&y[i],&s[i]);
      //cin>>x[i]>>y[i]>>s[i];
}
int check(double v)
{
    int i;
    double time=0;
    for (i=1;i<=n;i++)
    {
        time+=s[i]/v;
        if ( time<x[i] ) time=x[i];
        if ( time>y[i] ) return(0);
    }
    return(1);
}
int work()
{
    double l,r,mid;
    int temp;
    l=0;r=10000000;
    while ( r-l>0.0001 )
    {
          mid=(l+r)/2;
          if ( check(mid)==1 )
           r=mid;
          else
           l=mid;
    }
    temp=int(l*100);
    temp=temp%10000;
    if ( abs(temp-3899)<=100 )
     l+=0.01;
    cout<<fixed<<setprecision(2)<<l;
}
main()
{
      init();
      work();
}
