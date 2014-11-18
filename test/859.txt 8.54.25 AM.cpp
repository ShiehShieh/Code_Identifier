#include<stdio.h>
main()
{
 int a[10]={0},i=0,c,d=0,j,s=0;
 for(i=0;i<=9;i++)
 {scanf("%d ",&a[i]);
 }
 scanf("%d",&c);
 s=c+30;
 for(j=0;j<=9;j++)
  {
   if(s>=a[j])
   d++;
  }
 printf("%d",d);
}

