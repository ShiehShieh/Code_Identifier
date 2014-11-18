#include<iostream>
using namespace std;
int n,i,p[32];
long long f[32],ans;
void work(int k,int a,int b,int c){   //将k个最小的盘子从a柱移动到b柱，借助c柱
if (p[k]==c){//最大的这个盘子怎么会在c柱上？
cout<<-1;exit(1);}
if (k==1){
   if (p[k]==b)ans++;}
else
    if (p[k]==a)work(k-1,a,c,b);    //最大的那个盘子没有移动过，递归前半步
    else {
         ans+=f[k-1]+1;   //最大的那个盘子已经移动过了，增加ans，递归后半步
         work(k-1,c,b,a);
    }
}
int main(){
    cin>>n;
  for (i=1;i<=n;i++)cin>>p[i];
  f[1]=2;
  for (i=2;i<=n;i++){
    f[i]=f[i-1]*2;
 f[i-1]--;
}                            //f[i]=2^i-1
  work(n,1,2,3);
cout<<ans;
}
