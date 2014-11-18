#include "stdio.h"
#include "stdlib.h"

  int a[501][501];
  long s[501][501];
  long n;
   long max(long k1,long k2)
   {
     return k1>k2 ? k1 : k2;
   };
   long abs(long k)
   {
     return k>0 ? k : -k;
   };
   
   long v(long x1,long y1,long x2,long y2)
   {
      return (abs(x1-x2)+abs(y1-y2))*(abs(x1-x2)+abs(y1-y2));
   };
  
   long dp(long i ,long j)
       {
        if(s[i][j]!=-1)   return s[i][j];
        long x,y;        
        
        if(a[i][j]==1) 
        {
         s[i][j]=0;
         return s[i][j];
        };
        
         for(x=1;x<=n;x++) 
         {
           for(y=1;y<=n;y++)
           {
             if(a[x][y]<a[i][j])
               s[i][j]=max(s[i][j],dp(x,y)+v(x,y,i,j));
           };
         };    
          return s[i][j];
       };
  
   int main(){
       
   long sum;
   long t,i,j;
   long max=0;
   
      scanf("%ld",&n) ;
      
 for(i=1;i<=n;i++)    
 {
  for(j=1;j<=n;j++)
  {
    scanf("%ld",&a[i][j]);
     s[i][j]=-1;
  }; 
 };
 /*
 for(i=1;i<=n;i++)    
 {
  for(j=1;j<=n;j++)
  {
 printf("%ld ",a[i][j]); 
  }; 
   printf("\n");
 };
 */
 
   max=-1;
   
    for(i=1;i<=n;i++)
       {
        for(j=1;j<=n;j++)
            {
             if(a[i][j]==n*n) max=dp(i,j);
//              if(dp(i,j)>max) max=s[i][j];
            };
       };
                        
    printf("%ld\n",max);
    

      return 0;
       };
       


