#include<iostream>
#include<cmath>
using namespace std;
int n,k,a[40],ak[30],ans;
void  dfs(int aa,int num)
{
      for(int i=aa;i<=n-k+1+num-1;i++)
      {
      ak[num]=a[i];
      if(num==k)
      {
         int tem=0,flag=0;
         for(int i=1;i<=k;i++)
         {
                 tem+=ak[i];
         }
         for(int i=2;i<sqrt(tem);i++)if(tem%i==0)flag=1;
         if(!flag)ans++;
      }
      else dfs(i+1,num+1);
     }
      
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,1);
    cout<<ans;
}
