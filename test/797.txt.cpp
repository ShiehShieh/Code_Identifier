#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
short a[26],maxx=0,minn=101,i,f;
char c[100];bool m;
bool zs(int k){
     if (k==0||k==1)return false;
     if(k==2)return true;
     int q=(int)(sqrt (k));
     for(int i=2;i<=q;i++)
     if(k%q==0)return false;
     return true;}
int main(){
    cin>>c;
    for(i=0;i<strlen(c);i++)
    a[c[i]-'a']++;
    for(i=0;i<26;i++){
    if(a[i]>maxx)maxx=a[i];
    if(a[i]&&a[i]<minn)minn=a[i];}
    f=maxx-minn;
    m=zs(f);
    if(m)cout<<"Lucky Word"<<endl<<f;
    else cout<<"No Answer"<<endl<<0;
}

