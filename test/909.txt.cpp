#include <iostream>
#include <iomanip>
using namespace std;
int f[1500001][7]={0},ls[1500001]={0};
int max1(int a,int b){
    return a>b?a:b;
}
void pluss(int a,int b,int c){
     int i,t=0;
     for (i=0;i<max1(ls[a],ls[b]);i++){
         f[c][i]=f[a][i]+f[b][i]+t;
         t=f[c][i]/100000000;
         f[c][i]%=100000000;
     }
     while (t>0) {f[c][i++]=t%100000000;t/=100000000;}
     ls[c]=i;
}
int main(){
    int n,m,i,j,now=0;
    f[0][0]=ls[0]=1;
    while (cin>>n){
          n/=2;
          if(n>now)
            {for (i=now+1;i<=n;i++) pluss(i-1,i/2,i);
             now=n;
            }
          cout<<f[n][ls[n]-1];
          for (i=ls[n]-2;i>=0;i--) cout<<right<<setfill('0')<<setw(8)<<f[n][i];
          cout<<endl;
    }
    return 0;
}

