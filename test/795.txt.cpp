#include <stdio.h>
#include <math.h>
int i,n,t;
double c,r,l;
double x[101],y[101];
main(){
scanf("%d%lf",&n,&r);
for (i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
x[n+1]=x[1];
y[n+1]=y[1];
for (t=1;t<=n;t++) l+=sqrt(pow((x[t]-x[t+1]),2)+pow((y[t]-y[t+1]),2));
c=2*3.1415926*r;
l+=c;
printf("%.2lf",l);
return 0;
}

