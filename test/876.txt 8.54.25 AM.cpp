#include "stdio.h"
int main()
{
    float p,q;
    int i;
    scanf("%f%f",&p,&q);
    p=p/100;
    q=q/100;
    for(i=1;;i++)
      if((int)(i*q-0.000001)-(int)(i*p+0.000001)>=1)
        break;
    printf("%d",i);
    return 0;
}

