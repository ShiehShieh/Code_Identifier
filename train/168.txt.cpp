#include <iostream>
using namespace std;

int a[10000];

int pr1(int n)
{
    int i,j,t,j1,j2,m;
    for (i=n;i>0&&a[i]>=a[i+1];i--);
    if (i<=0)
    {
       return 0;
    }
    j=t=i+1;
    for (;t<=n&&a[i]<a[t];t++)
    {
        j=t;
    }
    m=a[i];
    a[i]=a[j];
    a[j]=m;
    j1=i+1;
    j2=n;
    for (;j1<j2;)
    {
        m=a[j1];
        a[j1]=a[j2];
        a[j2]=m;
        j1++;
        j2--;
    }
    return 1;
}
int main()
{
    int i,t,m,n,num=0;
    char z;
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>a[i]; 
    }
    t=1;
    while (t>0)
    {
          if (num==m)
          {
             for (i=1;i<=n;i++)
             {
                 cout<<a[i]<<' ';
             }
             return 0;
          }
          num++;
          t=pr1(n);
    }
    return 0;
}

