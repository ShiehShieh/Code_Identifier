#include<iostream>
using namespace std;
int n,a[50001],sum,ans[100001];
void cheng(int x)
{
     int i;
     for (i=1;i<=a[0];i++)
      a[i]*=x;
     for (i=1;i<a[0];i++)
     {
         a[i+1]+=a[i]/10;
         a[i]%=10;
     }
     while ( a[ a[0] ]>9 )
     {
           a[ a[0]+1 ]=a[ a[0] ]/10;
           a[ a[0] ]%=10;
           a[0]++;
     }
}
void work()
{
     int i=3,len,last;
     while (n>=2*i+1||n==i) 
     {
           sum++;
           ans[sum]=i;
           n-=i;i++;
     }
     if ( n!=0 )
     {
          if ( n-2>ans[sum] && n-2!=2 )
          {
               cheng(2);
               cout<<2<<" ";
               sum++;
               ans[sum]=n-2;
          }
          else
          {
              sum++;
              ans[sum]=n;
          }
     }
     n=ans[sum]-ans[sum-1];
     len=1;last=ans[sum];
     while (n>=3)
     {
           if ( n%2==1 )
           {
                last=last-n+2;
                len=len*n;
                n=1;
           }     
           else
           {
               n=n/2;
               last-=n;
               len=len*2;
           }
     }
     for (i=1;i<=sum-len+1;i++)
     {
         cheng(ans[i]);
         cout<<ans[i]<<" ";
     }
     for (i=2;i<=len;i++)
     {
         cout<<last+i-len<<" ";
         cheng(last+i-len);
     }
     cout<<endl;
     for (i=a[0];i>=1;i--)
      cout<<a[i];
}           
main()
{
      a[0]=a[1]=1;
      cin>>n;
      work();
}
