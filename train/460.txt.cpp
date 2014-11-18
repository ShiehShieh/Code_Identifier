/*  Vijos P1355  */

#include <iostream>
using namespace std;

long long Max,len,n;
long long w[1001],v[1001];
double f[1001];

void init()
{
     cin>>Max>>len>>n;
     for (long long i=1;i<=n;i++)
        scanf("%d%d",&w[i],&v[i]);
     f[0]=0;
     f[1]=len*1.0/v[1];
}

void dp()
{
     long long tsum,tmin;
     for (int i=2;i<=n;i++)
       {
             f[i]=INT_MAX;
             tsum=0;
             tmin=INT_MAX;
             for (int j=i;j>=1;j--)
               {
                  tsum=tsum+w[j];
                  tmin=min(tmin,v[j]);
                  if (tsum > Max)
                     break;
                  if (f[j-1]+len*1.0/tmin < f[i])
                     f[i]=f[j-1]+len*1.0/tmin;
               }
       }
}

void print()
{
     printf("%.1lf\n",f[n]*60);
}

int main(void)
{
    init();
    dp();
    print();
    return 0;
}
