#include<iostream>
using namespace std;
int gys(int x,int y){
    int t;
    while(x%y)
    {
    if (y>x)
    {
            t=x;
            x=y;
            y=t;
            }
              t=y;
              y=x-y;
              x=t;
              }
              return y;
}
int gbs(int x,int y)
{
    int a,b,c;
    a=x*y;
    b=gys(x,y);
    c=a/b;
    return c;
}
int main(){
       int p,q;
       cin>>p>>q;
       int s=0;
       int i,j;
       for (i=p;i<=q;i+=p)
       for (j=p;j<=q;j+=p)
       {
          if ((gys(i,j)==p)&&(gbs(i,j)==q)){
                                         s++;
                                         }
       }
       cout<<s;
       return 0;
           }

