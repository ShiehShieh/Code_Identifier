#include<iostream>
using namespace std;
int v[101],w[101];
int a[101][1001]={0};
main(){
       int n,t;
       int i,j;
       cin>>n>>t;
       for (i=1;i<=n;i++)
       {
           cin>>v[i]>>w[i];
       }
       for (i=1;i<=n;i++)
       for (j=1;j<=t;j++)
       {
           if (w[i]<=j){
                       a[i][j]=max(a[i-1][j-w[i]]+v[i],a[i-1][j]);
                       }
           else {
                a[i][j]=a[i-1][j];
                }
       }
       cout<<a[n][t];
       }

