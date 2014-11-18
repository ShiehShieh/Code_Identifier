#include<iostream>
using namespace std;
int a[1501],b[1501],c[1501],i,j,n;
main(){
cin>>n;
for(i=1;i<=n;i++)cin>>a[i];
for(i=1;i<=n;i++)
if(a[i]-a[i-1]>0){c[i]=1;b[i]=b[i-1]+a[i]-a[i-1]-1;}
else for(j=i-1;j>=1;j--){
if(b[j]-b[j-1]>0){c[i]=i-j+1;b[i]=b[j-1]+a[i]-a[j-1]-i+j-1;b[j]--;break;}
b[j]--;}
for(i=1;i<=n;cout<<c[i++]<<' ');}

