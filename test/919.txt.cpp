#include<iostream>
using namespace std;
int main(){
int n,i,y,m[1000],d[1000];
cin>>n;
for(i=0;i<n;i++){
cin>>y;
cin>>m[i];
cin>>d[i];}
for(i=0;i<n;i++){
if (   (d[i] == 30 && ( m[i] == 11 || m[i] == 9 ))
              || ( (m[i] + d[i]) % 2 == 0 ) )
cout<<"YES"<<"\n";
else cout<<"NO"<<"\n";}
return 0;
}

