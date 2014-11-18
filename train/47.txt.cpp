#include<iostream>
#include<cstring>
#define max(a,b) a>b?a:b
using namespace std;
string ins[2000];
int n,i,j,k,map[2000],opin;
int main(){
    cin>>n;
    opin=0;
    for(i=0;i<n;i++){
                     cin>>ins[i];
                     map[i]=1;
                     for(j=i-1;j>=0;j--){
                                         for(k=0;ins[j][k];k++) if(ins[j][k]!=ins[i][k]) break;
                                         if(!ins[j][k]) map[i]=max(map[j]+1,map[i]);
                                         }
                     opin=max(opin,map[i]);
                     }
    cout<<opin<<endl;
    return 0;
}
