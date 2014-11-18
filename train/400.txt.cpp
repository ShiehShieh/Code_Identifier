#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int maxx,minn,i,zm[26],t;char a[100];bool j;
int pzs(){
    if(t==0)return false;
    if(t==1)return false;
    if(t==2)return true;
    for(int y=2;y<=sqrt(t);y++)
    if(t%y==0)return false;
    return true;}
int main(){
    cin>>a;
    for(i=0;i<strlen(a);i++)
    zm[a[i]-'a']++;
    for(i=0;i<26;i++)
    if(zm[i]){maxx=zm[i];minn=zm[i];break;}
    for(;i<26;i++)
    if(zm[i]&&zm[i]>maxx)maxx=zm[i];
    if(zm[i]&&zm[i]<minn)minn=zm[i];
    t=maxx-minn;
    j=pzs();
    if(j==false)cout<<"No Answer"<<endl<<0;
    else cout<<"Lucky Word"<<endl<<t;
    return 0;}
