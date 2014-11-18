#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int b[10000]={0},c[10000]={0};
    int i,j,n;
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=1;i<=n;i++)
    {
        j=i;
        while(b[j]==b[j-1]) j--;
        c[i]=i-j+1;
        while(j<=n) //更新男生值
        {
            b[j]--;
            j++;
        }
    }
    printf("%d",c[1]);
    for(i=2;i<=n;i++)
       printf(" %d",c[i]);
    return 0;
}
