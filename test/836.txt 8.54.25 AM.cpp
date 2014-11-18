#include<stdio.h>
#include<math.h>
int n;
float l,r,pi=3.141526;
struct data
{
float y;
float x;
};
struct data pos[101];
float dis(int m,int n)
{
float t,d1,d2;
d1=pos[m].y;
d1=pos[n].y-d1;
d2=pos[m].x;
d2=pos[n].x-d2;
t=sqrt(d1*d1+d2*d2);
return t;

}
main()
{
int i;
scanf("%d %f",&n,&r);
for(i=1;i<=n;i++)
 {scanf("%f %f",&pos[i].y,&pos[i].x);
 
 }
for(i=2;i<=n;i++)
  l=l+dis(i,i-1);
l=l+dis(1,n);
l=l+2*pi*r;
printf("%.2f",l);
}

