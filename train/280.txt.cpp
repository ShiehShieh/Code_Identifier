#include <stdio.h>
int main()
{    
 	int a[7][2],b[7];
 	int daxiao(int x,int y);
 	
 	int i,j,z,t;
 	for(i=0;i<7;i++)
 {	  for(j=0;j<2;j++)
 	{
                      scanf("%d",&a[i][j]);
    }
                 
                  b[i]=a[i][1]+a[i][0];
  }
      t=0;
      for(i=1;i<7;i++)
      {
                     if( b[i]>b[t])
                      {t=i;}
                      
                      }
                      printf("%d",t+1);
                    return 0;
           }

