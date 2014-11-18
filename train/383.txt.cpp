#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXM 101 
#define MAXT 1001
int main(void)
{
    int T,M ,temp;
    int t[MAXM]={0},v[MAXM]={0};/**//*初始数组，很重要*/
    int i,j,k,d,h;
    int m[2][MAXT]={{0,0}};
    scanf("%d %d",&T,&M);
    
    for(i=1;i<= M;i++)
    scanf("%d %d",&t[i],&v[i]);
    
    memset(m,0,sizeof(m));
    
    for(i=1,d=0; i<= M; i++,d=(d+1)%2)
      {
     for(j=0,k=(d+1)%2 ; j<= T; j++)
     {
      m[k][j] = m[(k+1)%2][j] ;
      if(j>= t[i] && (temp=m[(k+1)%2][j-t[i]]+v[i])>m[k][j] )
      m[k][j]= temp ;
      
     }
    }
    
    if ( m[0][T] > m[1][T])
    printf("%d ",m[0][T]);
    else
    printf("%d ",m[1][T]);
    return 0;
}

