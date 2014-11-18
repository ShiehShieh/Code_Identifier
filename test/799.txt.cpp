#include<iostream>
using namespace std;
int main (){
int a[10],x,t,i;
for (i=0;i<10;i++)
cin>>a[i];
cin>>x;
for (i=0;i<10;i++)
if (a[i]<=x+30)
t++;
cout<<t;
return 0;
}
