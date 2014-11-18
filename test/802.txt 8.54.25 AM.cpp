#include<iostream>
#include<cmath>
using namespace std;
int prim(int a){
    int i=2,s=0,ans=1;
    while(i<=sqrt(a)){s=0;
                      while(a%i==0)
                      {s++;a/=i;}
ans*=(s+1);
i++;
}
if (a>1)
return ans*2;
else return ans;
}
main(){int k;
int i,t=0;
cin>>k;
if (k==1)
{cout<<1;
return 0;}
       for (i=2;i<=20000;i++)
       if(k==prim(i))
{t=1;
cout<<i;
return 0;}
if(t==0)
         cout<<"NO SOLUTION"; 
}

