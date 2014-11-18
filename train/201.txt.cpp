#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

int a[5000005],total=0;
bool flag[5000005];
int n,k;

bool isprime(int n)
{
    bool flag=true;
    for(int i=2;i<=(int)sqrt(n);i++)
       if(n%i==0)  flag=false;
    return flag;
}


void dfs(int count,int sum,int m)
{
    if(count==k)
    {
        if(isprime(sum))  total++;
        return;
    }
    else for(int i=m;i<=n;i++)
    {
        if(!flag[i])
        {
            sum+=a[i];
            flag[i]=true;
            dfs(count+1,sum,i+1);
            flag[i]=false;
            sum-=a[i];
        }
    }
}

int main()
{
    int i,j;

    
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
       scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        flag[i]=true;
        dfs(1,a[i],i+1);
    }
    printf("%d\n",total);
    return 0;
}







