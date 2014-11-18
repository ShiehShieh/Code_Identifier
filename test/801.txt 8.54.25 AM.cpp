#include<iostream>
using namespace std;
bool h[20000];
short vol[31];
short n,v,i,k,ans;
int main(){
    cin>>v;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>vol[i];
    memset(h,false,sizeof(h));
    h[0]=true;
    for(i=1;i<=n;i++)
    for(k=v;k>=vol[i];k--)h[k]=(h[k]|h[k-vol[i]]);
    for(i=v;i>=0;i--)
    if(h[i]){
    ans=i;
    break;}
    cout<<v-ans;
}
