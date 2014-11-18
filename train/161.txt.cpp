#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int i,j,k,h,n,m,num;
    int a[205];

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
       a[i]=i;
    j=1;
    for(i=1;i<=m;i++)
    {//每吃一只果子的标号为num，注意j没复原为关键
         res:
        h=i*i*i%5+1;
        j+=h;
        if(j>n)
        {
            j=1;
            goto res;
        }
        num=a[j];
        for(k=j;k<n;k++)
           a[k]=a[k+1];
        n--;
    }
    printf("%d\n",num);
    return 0;
}

    
    
    
