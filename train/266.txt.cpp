#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int qkpass(char a[],int i,int j)
{
    char k=a[i];
    while(i<j)
    {
        while(a[j]<=k && i<j) j--;
        a[i]=a[j];
        while(a[i]>=k && i<j) i++;
        a[j]=a[i];
    }
    a[i]=k;
    return i;
}

void qksort(char a[],int i,int j)
{
    int k;
    if(i<j)
    {
        k=qkpass(a,i,j);
        qksort(a,i,k-1);
        qksort(a,k+1,j);
    }
}

long long dao(char a[],int t)
{
    long long s=0,j=1;
    for(int i=0;i<=t;i++,j*=10)
        s+=(a[i]-48)*j;
    return s;
}

int main()
{
    char a[11];
    long long b[30];
    cin.getline(a,11);
    while(a[0]!='\0')
    {
        short t=strlen(a)-1;
        b[0]=atoll(a);
        for(short i=1;;i++)
        {
            qksort(a,0,t);
            b[i]=atoll(a)-dao(a,t);
            if(log10(b[i])<t) b[i]*=10;
            bool flag=false;
            for(short j=0;j<i;j++)
            {
                if(flag) cout<<' '<<b[j];
                if(b[i]==b[j])
                {
                    flag=true;
                    cout<<b[j];
                }
            }
            if(flag)
            {
                cout<<endl;
                break;
            }
            lltoa(b[i],a,10);
        }
        cin.getline(a,11);
    }
    return 0;
}

