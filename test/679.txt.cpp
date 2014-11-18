#include <iostream>
#include <string.h>
using namespace std;
short y[10][5]={{1,4,0,4,1},{0,2,0,2,0},{1,2,1,3,1},{1,2,1,2,1},{0,4,1,2,0},{1,3,1,2,1},{1,3,1,4,1},{1,2,0,2,0},{1,4,1,4,1},{1,4,1,2,1}};
main () {
     short k,l,u,i,j;
     char s[256];
     cin>>k>>s;
     l=strlen (s);
     for (i=0;i<5;i++) {
         if ((i==2||i==4)&&u<k-1) {i--;u++;}
         else u=0;
     for (j=0;j<l;j++) {
         short t=int(s[j]-'0');
         short x;
         if (y[t][i]==0) {for (x=0;x<k+2;x++) cout<<' ';}
         else if (y[t][i]==1) {cout<<' ';for (x=0;x<k;x++) cout<<'-';cout<<' ';}
         else if (y[t][i]==2) {for (x=0;x<k+1;x++) cout<<' ';cout<<'|';}
         else if (y[t][i]==3) {cout<<'|';for (x=0;x<k+1;x++) cout<<' ';}
         else if (y[t][i]==4) {cout<<'|';for (x=0;x<k;x++) cout<<' ';cout<<'|';}
         if (j<l-1) cout<<' ';}
         if (i<4) cout<<'\n';}}
