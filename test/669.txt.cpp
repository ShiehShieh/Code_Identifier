#include<stdio.h>
main()
{
      int i,apple[11],high,s=0;
      for(i=0;i<10;i++)
      {scanf("%d",&apple[i]);
       apple[i]-=30;
      }
      scanf("%d",&high);
      for(i=0;i<10;i++)
      if(high>=apple[i])s++;
      printf("%d",s);
}

