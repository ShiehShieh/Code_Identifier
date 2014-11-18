#include <cstdio>
#include <cmath>

#define eps 1e-7

int main()
{
	double p,q,m;
	m=0;
	scanf("%lf %lf",&p,&q);
	p/=100.0;
	q/=100.0;
	while (!(p*m<floor(q*m-eps)&&floor(q*m+eps)<q*m))
		m+=1.0;
	printf("%.0lf\n",m);
	return 0;
}
