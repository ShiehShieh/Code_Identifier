#include <stdio.h>
#include <stdlib.h>
double a,b,c,d;
long tot=0;
double x,ans[5];
void read(void)
{
scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
}
void work(void)
{
double sum;
for(x=-100;x<=100;x+=0.01)
  {sum=a*x*x*x+b*x*x+c*x+d;
if(sum==0||(sum+0.0001>0&&sum<0)||(sum>0&&sum-0.0001<0))
{
ans[tot]=x;
tot++;
}
}
}
void write(void)
{
long i;
for(i=0;i<tot;i++)
 printf("%0.2lf ",ans[i]);
}
int main(void)
{
read();
work();
write();
return(0);
}

