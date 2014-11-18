#include <iostream>
using namespace std;

typedef int array[111];

void input(array &a)
{
     char c[112],k;
     cin>>c;
     k=strlen(c);
     for (int i=1;i<=k;i++)
         a[i]=c[k-i]-'0';
}

void cheng(array a,int b,array &c)
{
     array d;
     memset(d,0,sizeof(d));
     int i;
     for (i=1;i<=110;i++)
         d[i]=a[i]*b;
     for (i=1;i<110;i++)
     {
         d[i+1]=d[i+1]+d[i]/10;
         d[i]=d[i]%10;
     }
     memcpy(c,d,sizeof(d));
}

void jian(array a,array b,array &c)
{
     array d;
     memset(d,0,sizeof(d));
     int i;
     for (i=1;i<=110;i++)
         d[i]=a[i]-b[i];
     for (i=1;i<110;i++)
         if (d[i]<0) {d[i+1]--;d[i]+=10;}
     memcpy(c,d,sizeof(d));
}

void jia(array a,int b,array &c)
{
    c[1]=a[1]+b;
    for (int i=1;i<110;i++)
    {
        c[i+1]=c[i+1]+c[i]/10;
        c[i]=c[i]%10;
    }
}
        
void chu(array a,int b,array &c)
{
    array d;
    memset(d,0,sizeof(d));
    int i,r=0;
    for (i=110;i>=1;i--)
    {
        r=r*10+a[i];
        d[i]=r/b;
        r=r-d[i]*b;
    }
    memcpy(c,d,sizeof(d));
}

int compare(array a,array b)
{
    for (int i=110;i>=1;i--)
    {
        if (a[i]>b[i]) return 1;
        if (a[i]<b[i]) return -1;
    }
    return 0;
}

void output(array a)
{
    int i,l=110;
    while (a[l]==0) l--;
    for (i=l;i>=1;i--) cout<<a[i];
}

int main()
{
    array a,b;
    memset(a,0,sizeof(a));
    input(a);
    memset(b,0,sizeof(b));
    b[1]=1;
    while (compare(a,b)>-1) cheng(b,2,b);
    chu(b,2,b);
    jian(a,b,b);
    cheng(b,2,b);
    jia(b,1,b);
    output(b);
    cout<<endl;
    return 0;
}
