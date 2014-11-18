#include<iostream>
using namespace std;

int main() {
int n,i,x,sum=0;
cin>>n;
int a[20000+1]={0},q1[n],tou1=0,wei1=0,q2[n],tou2=0,wei2=0;
for(i=0;i<n;i++) {cin>>x;a[x]++;}
for(i=1;i<=20000;) 
if(a[i]) {q1[wei1++]=i;a[i]--;} 
else i++;
while(n>=2){
if(wei1-tou1>=2&&(wei2==tou2||q2[tou2]>q1[tou1+1])) x=q1[tou1]+q1[tou1+1],tou1+=2; 
else if(wei2-tou2>=2&&(wei1==tou1||q1[tou1]>q2[tou2+1])) x=q2[tou2]+q2[tou2+1],tou2+=2; 
else x=q1[tou1++]+q2[tou2++];
{q2[wei2++]=x;sum=sum+x;n--;}
}
cout<<sum;
return 0; //powered by nehalem 
} 

