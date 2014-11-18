/*  Vijos P1165  */
#include <iostream>
using namespace std;

int n;
int a[20001],b[20001];
int ans,tmax;

void qksort(int b1,int e)
{
     int i,j;
     int k;
     int t;
     if (b1<e)
       {
             i=b1; j=e;
             k=a[i];
             t=b[i];
             while (i<j)
               {
                   while (i<j && a[j]>=k) j--;
                   a[i]=a[j];b[i]=b[j];
                   while (i<j && a[i]<=k) i++;
                   a[j]=a[i];b[j]=b[i];
               }
             a[i]=k;
             b[i]=t;
             qksort(b1,i-1);
             qksort(i+1,e);
       }
}

void init()
{
     cin>>n;
     for (int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
     qksort(1,n);
     ans=b[1]-a[1];
     tmax=b[1];
}

void work()
{
     for (int i=2;i<=n;i++)
       {
          if ( a[i]<tmax && b[i]>tmax )
            {
               ans+=(b[i]-tmax);
               tmax=b[i];
            }
          else
            if ( a[i] > tmax )
              {
                 ans+=(b[i]-a[i]);
                 tmax=b[i];
              }
       }
}

void print()
{
     cout<<ans<<endl;
}

int main(void)
{
    init();
    work();
    print();
    return 0;
}
