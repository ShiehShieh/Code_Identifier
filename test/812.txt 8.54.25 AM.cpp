#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
       long i,j,n,a[101],sum=0,temp,jishu=0;
       scanf("%d",&n);
       for(i=0;i<n;i++)
           scanf("%d",&a[i]);
       for(i=0;i<n;i++)
           sum+=a[i];
       sum/=n;
       for(i=0;i<n;i++)
       {
           temp=a[i]-sum;
           if(temp!=0)
           {
               a[i+1]+=temp;
               jishu++;
           }
       }
       printf("%d\n",jishu);
       return 0;
}


