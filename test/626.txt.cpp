/*Vijos P1520*/
#include<iostream>
using namespace std;
long n,a[2000],b[2000],fx,l,i,j,k,f[2000],x=0;
int main()
{
    cin>>n;
    for (i=2;n>=i;i++)
    {
        f[x++]=i;
        n-=i;
    }
    for (i=x-1;n>0;i--)
    {
        f[i]++;
        n--;
    }
    memset(a,0,sizeof(a));
    l=1;
    a[0]=1;
    for (i=0;i<x;i++)
    {
        memset(b,0,sizeof(b));
        fx=l;
        for (j=0;j<l;j++)
        {
            b[j]+=a[j]*f[i];
            k=j;
            while (b[k]>9)
            {
                  b[k+1]+=b[k]/10;
                  b[k]%=10;
                  k++;
                  if (k>=fx) fx=k+1;
            }
        }
        l=fx;
        memcpy(a,b,sizeof(a));
    }
    for (i=0;i<x-1;i++) cout<<f[i]<<" ";
    cout<<f[x-1]<<endl;
    for (i=l-1;i>=0;i--) cout<<a[i];
    cout<<endl;
    return 0;
}

