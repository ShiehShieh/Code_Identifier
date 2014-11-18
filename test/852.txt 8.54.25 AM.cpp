#include <stdio.h>
#include <math.h>
#define gold 0.6180339887498949
int main() 
{
    long i,j,m,n,max,a[100010]={0},b[30010]={0},ws1,ws2;
    double k,minex;
    minex=10;
    scanf("%d",&n);
    max=-1;
    for(i=0;i<n;i++)
    {
       scanf("%d",&j);
       a[j]++;
       if(max<j)
         max=j;
    }
    for(i=0,m=0;i<=max;i++)
      for(j=0;j<a[i];j++)
      {
         b[m]=i;
         m++;
      }
    i=0;j=1;
    while(j<n)
    {
             k=(double)b[i]/(double)b[j];
             if(fabs(k-gold)<minex)
             {
                                    minex=fabs(k-gold);
                                    ws1=i;
                                    ws2=j;
             }
             if(k<gold) i++;
             else j++;
    }
    printf("%d\n%d",b[ws1],b[ws2]);
    return 0;
}
