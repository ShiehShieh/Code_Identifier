#include<iostream>
using namespace std;
int s,m,i,j,t[100],v[100],dp[1000]={0};
int main(){
cin>>m>>s;
for(i=0;i<m;i++) cin>>v[i]>>t[i];
for(i=0;i<m;i++){
for(j=s;j>0;j--){
if(t[i]<=j) if(v[i]+dp[j-t[i]]>dp[j]) dp[j]=v[i]+dp[j-t[i]];
}
}
cout<<dp[s]<<endl;
} 

