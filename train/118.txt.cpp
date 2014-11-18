#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

bool f[10005];
int h[10005];

int main()
{

    int n,m;
    scanf("%d",&n);
    int maxn=0;
    memset(h,0,sizeof(h));
    for(int k=1;k<=n;k++)
    {
        int t,high,HIGH=0;
        scanf("%d",&t);
        memset(f,false,sizeof(f));
        f[0]=true;
        while(t!=-1)
        {
            high=HIGH;
            for(int i=high+1;i>=0;i--)
            {
                if(f[i])
                {
                    f[i+t]=true;
                    if(i+t>HIGH) HIGH=i+t;
                }
            }
            scanf("%d",&t);
        }
        for(int i=0;i<=HIGH;i++)
           if(f[i])  h[i]++;
        if(HIGH>maxn)  maxn=HIGH;
    }
    for(int i=maxn;i>=0;i--)
    {
        if(h[i]==n)
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
