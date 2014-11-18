#include<stdio.h>
struct std
{
 int x1,y1,x2,y2;
}w[101];
int main()
{
  int n,i,j,k,size,a,b,c,d;
  char ask[11];
  scanf("%d\n",&n);
  size=0;
  for(i=1;i<=n;i++)
  {
   scanf("%s ",ask);
   if(ask[0]=='O'){
                   size++;
                   scanf("%d %d %d %d\n",&w[size].x1,&w[size].y1,&w[size].x2,&w[size].y2);
                   }
   if(ask[0]=='C'&&ask[2]=='i')
                   {
                    scanf("%d %d\n",&a,&b);
                    for(j=size;j>=1;j--)
                    if(a>=w[j].x1&&a<=w[j].x2&&b>=w[j].y1&&b<=w[j].y2)break;
                    if(j==0)continue;
                    w[size+1]=w[j];
                    for(k=j;k<=size;k++)w[k]=w[k+1];
                    }
   if(ask[0]=='C'&&ask[2]=='o'){
                    scanf("%d %d\n",&a,&b);
                    for(j=size;j>=1;j--)
                    if(a>=w[j].x1&&a<=w[j].x2&&b>=w[j].y1&&b<=w[j].y2)break;
                    if(j==0)continue;
                    for(k=j;k<size;k++)w[k]=w[k+1];
                    size--;
                    }
  
   if(ask[0]=='M'){
                   scanf("%d %d %d %d\n",&a,&b,&c,&d);
                    for(j=size;j>=1;j--)
                    if(a>=w[j].x1&&a<=w[j].x2&&b>=w[j].y1&&b<=w[j].y2)break;
                    if(j==0)continue;
                    w[size+1]=w[j];
                    for(k=j;k<=size;k++)w[k]=w[k+1];
                    w[size].x1+=c;w[size].x2+=c;
                    w[size].y1+=d;w[size].y2+=d;
                   }                                    
  }  
  if(size==0)printf("Nothing\n");
  else printf("%d %d %d %d\n",w[size].x1,w[size].y1,w[size].x2,w[size].y2);
  return 0;
}

