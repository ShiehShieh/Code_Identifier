#include <iostream>
using namespace std;
int main(){
    double s=0.0,n;
    int i=1,k;
    cin>>k;
    while(s<=k)
      {n=1.00/i;
       s=s+n;
       i++;
      }
    cout<<i-1;
return 0;
}
