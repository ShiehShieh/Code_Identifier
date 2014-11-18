#include<iostream>
using namespace std;
int main(){
    int n,s,i=0,k;
    bool j=false;
    long an[81]={};
    cin>>n;
    
    an[81]=2;
    for(s=1;s<=n;s++)
      
      for(k=81;k>=1;k--){
      if(j==true) an[k]=an[k]*2+1; else an[k]=an[k]*2;
      j=false;
      if(an[k]>=10) {an[k]-=10; j=true;}} 
      
    j=false;
    an[81]-=2;
    
    for(k=81;k>=1;k--){
        if(j==true) {an[k]=an[k]-1; j=false;}
        if(an[k]<0) {an[k]=an[k]+10;  j=true;}}    
       
    for(k=1;k<=81;k++)
    if(an[k]==0&&an[k+1]!=0)
       {i=k+1;
       break;}
       
    for(i;i<=81;i++)
       cout<<an[i];

return 0;
}


