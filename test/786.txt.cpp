#include<iostream>
using namespace std;
int f[20000];
int main(){
    int n,w;
    cin>>n>>w;
    int i,j,k,a[w];
    for(i=0;i<w;i++)
    cin>>a[i];
    f[0]=1;
    for(i=0;i<w;i++)
    for(j=n-1;j>=0;j--){
                        if(f[j]!=0&&j+a[i]<=n)
                        f[j+a[i]]=1;
    }
    j=n-1;
    while(f[j]==0)j--;
    cout<<n-j;
}
