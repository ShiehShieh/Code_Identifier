#include<iostream.h>
#include<math.h>
#include<cstdio>
int main()
{  int n;
   float r,tol=0,k=0,x[3],y[3],pai;
	scanf("%d%f",&n,&r);
    scanf("%f%f",&x[1],&y[1]);
	x[0]=x[1];
	y[0]=y[1];
	pai=3.1415926;
	for (int i=2;i<=n;i++)
	{scanf("%f%f",&x[2],&y[2]);
	 k=(x[1]-x[2])*(x[1]-x[2]);
	 k+=(y[1]-y[2])*(y[1]-y[2]);
	 tol=tol+sqrt(k);
	 x[1]=x[2];
	 y[1]=y[2];
	}
     k=(x[1]-x[0])*(x[1]-x[0]);
	 k+=(y[1]-y[0])*(y[1]-y[0]);
	tol=tol+sqrt(k);
	 r=2*pai*r;
	 tol=tol+r;
	 printf("%.2f",tol);

	return 0;

}
