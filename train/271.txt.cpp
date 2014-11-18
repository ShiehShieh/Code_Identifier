#include<iostream>
using namespace std;
int a[50][400][400];
main(){
       int s1[50],v1[50],k1[50];
       int s,v,n,i,j,l,k;
       cin>>v>>s;
       cin>>n;
       for (i=1;i<=n;i++)
       {
           cin>>v1[i]>>s1[i]>>k1[i];
       }
       for (i=1;i<=n;i++)
       for (j=1;j<=v;j++)
       for (k=1;k<=s;k++)
       {
           if (j>=v1[i]&&k>=s1[i]){
                                   a[i][j][k]=max(a[i-1][j-v1[i]][k-s1[i]]+k1[i],a[i-1][j][k]);
                                   }
           else{
                a[i][j][k]=a[i-1][j][k];
                }
       }
       cout<<a[n][v][s];
       }

