#include <stdio.h>
#include <string.h>
int main()
{
     int l,m,i,j,s=0,x,y;
     scanf("%d %d",&l,&m);
     char a[l+1];
     memset(a,0,l+1);
     for (i=0;i<m;i++){
         scanf("%d %d",&x,&y);
         memset(a+x,1,y-x+1);
     }
     for (i=0;i<=l;i++) if (a[i]==0) s++;
     printf ("%d\n",s);
     return 0;
}

