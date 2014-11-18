#include <iostream>

using namespace std;

int main()
{ int a[7],b[7],i,t,y ;
  for(i=1;i<=7;i++)
  cin>>a[i]>>b[i];
  t=a[1]+b[1];
   for(i=1;i<=7;i++)
   if(a[i]+b[i]>t)
   { 
     t=a[i]+b[i];y=i;}
   if(t>8) cout<<y;
   else cout<<0<<endl;
    return 0;
}

