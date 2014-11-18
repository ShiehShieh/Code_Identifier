#include<iostream>
using namespace std;
int a[1001];
int main()
{
   int i,n,tmp;
   int s=0;
   memset(a,0,sizeof(a));
   cin>>n;
   for(i=1;i<=n;i++)
     {
                    cin>>tmp;a[tmp]++;
                    }
   for(i=1;i<=1000;i++)
   {
                    if(a[i]>0)s++;
                    }
   cout<<s<<endl;
   for(i=0;i<=1000;i++)
   if(a[i]>0)
   cout<<i<<" ";
   cout<<endl;
   return 0;
}

