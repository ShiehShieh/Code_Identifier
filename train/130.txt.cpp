#include<iostream>
using namespace std;
int main()
{
     double f[1001],w[1001],v[1001];
     double t,minv;
	long i,j,k,l,n,m,max1,len;
	scanf("%ld%ld%ld",&max1,&len,&n);

	for (i=1;i<=n;i++)
		scanf("%lf%lf",&w[i],&v[i]);

	f[1]=len/v[1];
	f[0]=0;
	for (i=2;i<=n;i++)
	{
		f[i]=999999999;
		t=0;
		minv=999999999;
		for (j=i;j>=1;j--)
		{
			t=t+w[j];
			if (v[j]<minv) minv=v[j];
			if (t>max1) break;
			if (f[j-1]+len/minv<f[i]) f[i]=f[j-1]+len/minv;
		}

	}
		/*for (i=1;i<=n;i++)
		{f[i]=f[i]*60;
			printf("%lf   ",f[i]);
		}*/
	f[n]=f[n]*60;
	printf("%0.1lf\n",f[n]);
	return 0;
}
