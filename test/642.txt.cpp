/*  Vijos P1380  */

#include <iostream>
using namespace std;

int main(void)
{
    int a,b;
    int police[1001];
    
    int j,t;
    int ans=0;
    
    cin>>a>>b;
    for (int i=1;i<=a;i++)
       cin>>police[i];
    
    for (int i=1;i<a;i++)
       for (j=i+1;j<=a;j++)
          if (i*police[i] == j*police[j])
             t=(i+j)/2;
    j=t;
    
    if (b==0)
      {
             for (int i=1;i<=j;i++)
                ans=ans+police[i];
      }
    else
      {
             for (int i=a;i>=j;i--)
                ans=ans+police[i];
      }
    
    cout<<j<<" "<<ans<<endl;
    return 0;
}
