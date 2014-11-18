#include<iostream>
using namespace std;
short n,m,p,i,j;
int v,zone[30000];
int main(){
cin>>n;
cin>>m;
for(i=1;i<=m;i++){cin>>v;
cin>>p;
for(j=n;j>=1;j--)
if(v<=j&&p*v+zone[j-v]>zone[j])
zone[j]=p*v+zone[j-v];}
cout<<zone[n];}

