#include<iostream>
using namespace std;
int main(){
    int i,n,a[11],b[11];
    long long ans,add;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      cin>>a[i]>>b[i];
    ans=b[0];
    i=1;
    add=a[0];
    while(i<n)
      {while(ans%a[i]!=b[i])
         ans+=add;
       add=add*a[i];
       i++;
      }
    cout<<ans;
return 0;
}
