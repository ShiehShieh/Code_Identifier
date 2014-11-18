#include<iostream>
#include<cstdio>
#define max(a,b) a>b?a:b
using namespace std;
long long n,t,ins[1000],i,j,k;
double m,in,s,tim[1000],dp[1000],map[1000][1000];
int main(){
    cin>>t>>m>>n;
    for(i=1;i<=n;i++){
                      cin>>ins[i]>>in;
                      in/=60;
                      tim[i]=m/in;
                      }
    memset(map,0,sizeof(map));
    for(i=1;i<=n;i++){
          k=ins[i];
          s=tim[i];
          for(j=i;j<=n&&k<=t;){
                map[i][j]=s;
                ++j;
                s=max(s,tim[j]);
                k+=ins[j];
                }
          }
    dp[0]=0.0;
    for(i=1;i<=n;i++){
          dp[i]=99999999.0;
          for(j=1;j<=i;j++)
                if(map[j][i]>0) dp[i]=min(dp[j-1]+map[j][i],dp[i]);
          }
    printf("%.1lf",dp[n]);
    return 0;
}

