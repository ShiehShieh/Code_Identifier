#include <iostream>
using namespace std;
#define MaxN 10000
int n;
short a[MaxN+1]={0};
bool b[MaxN+1]={0};
int sweep(bool t,int p){
 if(p<n){
 if(t==1){
 if(a[p] == 3){ //3个雷
 if( b[p]==1 && b[p-1]==1 )b[p+1] = 1;
 else return 0;
 }
 else if(a[p] == 2){ //2个雷
 if( b[p]==0 &&( b[p-1]==0) ) return 0;
 if( b[p]==1 &&( b[p-1]==1) ) b[p+1] = 0;
 if( ( b[p]==0 && b[p-1]==1)||
 ( b[p]==1 && b[p-1]==0) ) b[p+1] = 1;
 }
 else if(a[p] == 1){//1个雷
if( b[p]==0 &&( b[p-1]==0) ) b[p+1] = 1;
if( b[p]==1 &&( b[p-1]==1) ) return 0;
 if( ( b[p]==0 && b[p-1]==1)||
 ( b[p]==1 && b[p-1]==0) ) b[p+1] = 0;
 }
 else { //0个雷
if( b[p]==0 &&( b[p-1]==0) ) b[p+1] = 0;
else return 0;
 }
 return sweep(1,p+1);
 }
 }
 else{

 if(a[p] == 3){ //3个雷
 return 0;
 }
 else if(a[p] == 2){ //2个雷
 if( b[p]==1 &&( b[p-1]==1) ) return 1;
 return 0;
 }
 else if(a[p] == 1){//1个雷
 if( (b[p]==0 && b[p-1]==1)||
 (b[p]==1 && b[p-1]==0) ) return 1;
 else return 0;
 }
 else { //0个雷
if( b[p]==0 && b[p-1]==0 ) return 1;
else return 0;
 }
 }
 return 0;
 /*
 else {
 if(a[p] == 3){ //3个雷
 if( b[p-1]==1) b[p] = b[p+1] = 1;
 else return 0;
 }
 else
 if(a[p] == 2){ //2个雷
 if( b[p]==0)&&( b[p-1]==0) ) return ;
 if( b[p]==1)&&( b[p-1]==1) ) b[p+1] = 0;
 if( b[p]==0)&&( b[p-1]==1)||
( b[p]==1)&&( b[p-1]==0) ) b[p+1] = 1;
 }
 else if(a[p] == 1){//1个雷
if( b[p]==0)&&( b[p-1]==0) ) b[p+1] = 1;
if( b[p]==1)&&( b[p-1]==1) ) return ;
 if( b[p]==0)&&( b[p-1]==1)||
( b[p]==1)&&( b[p-1]==0) ) b[p+1] = 0;
 }
 else { //0个雷
if( b[p]==0)&&( b[p-1]==0) ) b[p+1] = 0;
else return 0;
 }
 }
 */
}
int main(){
int i,j,d;
cin>>n;
for(i=1;i<=n;i++)cin>>a[i];
if(a[1]==1){
b[1]=1;
d=sweep(1,2);
b[1]=0;
memset( b,0,sizeof(b));
b[2]=1;
cout<< d+sweep(1,2) ;
}
else if(a[1]==2){
b[1] = b[2] = 1;
cout<< sweep(1,2) ;
}
else if(a[1]==0){
cout<< sweep(1,2) ;
}
else cout<<0;
//while(1);
return 0;
}
