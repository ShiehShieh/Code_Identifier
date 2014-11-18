#include<iostream>
using namespace std;
bool f[10002];
int h[10002];
int main()
{   memset(h,0,sizeof(h));
    int n,m;
    cin>>n;
    int max=0;
    for (int k=1;k<=n;k++)
        {int t,high,HIGH=0;
         cin>>t;
         memset(f,false,sizeof(f));
         f[0]=true;
         while (t!=-1) 
               {high=HIGH;
                for (int i=high+1;i>=0;i--) 
                    if (f[i])
                       {f[i+t]=true;
                        if (i+t>HIGH) HIGH=i+t;
                       }
                cin>>t;
               }
         for (int i=0;i<=HIGH;i++)if (f[i]) h[i]++;
         if (HIGH>max) max=HIGH;
        }
    for (int i=max;i>=0;i--)
        if (h[i]==n)
           {cout<<i;
            break;
           }
}

