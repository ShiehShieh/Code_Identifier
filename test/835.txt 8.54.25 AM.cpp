#include <iostream>
using namespace std;
int fd(int *a,int n)
{
    int t=a[0],k=0;
    for (int i=1;i<n;i++)
    if (a[i]<t)
    {
        a[k++]=a[i];
        a[i]=a[k];
    }
    a[k]=t;
    return k;
}
void kp(int *a,int n)
{
    if (n>1)
    {
        int m=fd(a,n);
        kp(a,m);
        kp(a+m+1,n-m-1);
    }
}
int main()
{
    int n;
    cin>>n; 
    int a[10003],b[10003];
    memset(b,63,sizeof(b));
    a[n]=a[n+1]=1000000000;
    for (int i=0;i<=n-1;i++)
    cin>>a[i];
    kp(a,n);
    int ta=0,tb=1,s=0;
    for (int i=1;i<=n-1;i++)
    {
        if (a[ta+1]<b[tb])
        {
            s+=b[i]=a[ta]+a[ta+1];
            ta+=2;
        }else
        {
            if (b[tb+1]>a[ta])
            {
                s+=b[i]=a[ta]+b[tb];
                ta++;
                tb++;
            }else
            {
                s+=b[i]=b[tb]+b[tb+1];
                tb+=2;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
    
