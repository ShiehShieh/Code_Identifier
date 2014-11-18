#include<iostream>
using namespace  std;
int main()
{
    int m,top,last,sum;
    cin>>m;
    top=1;
    last=top+1;
    while(top<m-1){
                   sum=(top+last)*(last-top+1)/2;
                   if (sum==m){
                               cout<<top<<" "<<last<<"\n";
                               top++;
                               last++;
                               }
                   if (sum>m){
                              top++;
                              }
                   if (sum<m){
                              last++;
                              }
    }
    return 0;
}

