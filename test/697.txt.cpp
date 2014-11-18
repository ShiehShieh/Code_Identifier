#include <iostream>
using namespace std;

typedef int array[10001];

void cheng(array a,int b,array &c)
{
    array d;
    memset(d,0,sizeof(d));
    int i;
    for (i=1;i<=10000;i++) d[i]=a[i]*b;
    for (i=1;i<10000;i++)
    {
        d[i+1]=d[i+1]+d[i]/10;
        d[i]=d[i]%10;
    }
    memcpy(c,d,sizeof(d));
}

void output(array a)
{
    int i,l=10000;
    while (a[l]==0) l--;
    for (i=l;i>=1;i--) cout<<a[i];
}

int main()
{
    int n,i,s=0,t,g;
    array a;
    memset(a,0,sizeof(a));
    a[1]=1;
    cin>>n;
    int f[10001];
    i=1;
    while (s<=n)
    {
        i++;
        f[i-1]=i;
        s+=i;
    }
    s-=i;
    t=n-s;
    g=i=i-2;
    while (t>=1&&i>=1)
    {
        f[i]++;
        i--;
        t--;
    }
    if (t==1) f[g]++;
    for (i=1;i<=g;i++) 
    {
        cout<<f[i]<<' ';
        cheng(a,f[i],a); 
    }
    cout<<endl;
    output(a);
    cout<<endl;
    return 0;
}
