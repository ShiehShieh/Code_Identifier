#include <stdio.h>

int main()
{
	double l,v;
	scanf("%lf %lf",&l,&v);
	printf("%.1lf\n",l/1.5);
	printf("%.1lf\n",l/(v*1.5));
	return 0;
}

