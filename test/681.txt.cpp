#include <iostream>
using namespace std;

typedef int array[5001];

void input(array &a)
{
    char c[10001];
    memset(a,0,sizeof(a));
    cin>>c;
    int k=strlen(c),i,j=0;
    for (i=k-1;i-4>=0;i=i-4)
    {
        j++;
        a[j]=(c[i]-'0')+(c[i-1]-'0')*10+(c[i-2]-'0')*100+(c[i-3]-'0')*1000;
    }
    j++;
    if (i>=0) a[j]+=(c[i]-'0');
    if (i>=1) a[j]+=(c[i-1]-'0')*10;
    if (i>=2) a[j]+=(c[i-2]-'0')*100;
    if (i>=3) a[j]+=(c[i-3]-'0')*1000;
}

void cheng(array a,array b,array &c)
{
     int i,j;
     for (i=1;i<=2500;i++)
         for (j=1;j<=2500;j++)
         {
             c[i+j-1]+=a[i]*b[j];
             c[i+j]+=c[i+j-1]/10000;
             c[i+j-1]=c[i+j-1]%10000;
         }
     for (i=1;i<5000;i++)
     {
         c[i+1]=c[i+1]+c[i]/10000;
         c[i]=c[i]%10000;
     }
}

void output(array a)
{
    int i,l=5000;
    while (a[l]==0) l--;
    cout<<a[l];
    for (i=l-1;i>=1;i--)
    {
        cout<<a[i]/1000;
        cout<<a[i]/100%10;
        cout<<a[i]/10%10;
        cout<<a[i]%10;
    }
}

int main()
{
    array a,b,c;
    input(a);
    input(b);
    memset(c,0,sizeof(c));
    cheng(a,b,c);
    output(c);
    cout<<endl;
    return 0;
}
