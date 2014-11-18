#include <cstdio>

__int64 ans[1000];
int ansn=0;

bool find(__int64 n)
{
	int i;
	for (i=0; i<ansn; i++)
		if (n==ans[i])
		{
			int j;
			for (j=i; j<ansn-1; j++)
				printf("%I64d ",ans[j]);
			printf("%I64d\n",ans[ansn-1]);
			return true;
		}
	return false;
}

void qsort(int a[],int l,int r)
{
	int i,j,x;
	i=l; j=r; x=a[l];
	while (i<j)
	{
		while (i<j&&a[j]>=x)
			j--;
		if (i<j)
			a[i++]=a[j];
		while (i<j&&a[i]<=x)
			i++;
		if (i<j)
			a[j--]=a[i];
		a[i]=x;
	}
	if (l<i-1)
		qsort(a,l,i-1);
	if (i+1<r)
		qsort(a,i+1,r);
}

int main()
{
	int m,i;
	__int64 n,l,r;
	int a[20];
	while (scanf("%I64d",&n)!=EOF)
	{
		ansn=0;
		while (!find(n))
		{
			ans[ansn++]=n;
			m=0;
			while (n)
			{
				a[m++]=n%10;
				n/=10;
			}
			qsort(a,0,m-1);
			l=r=0;
			for (i=0; i<m; i++)
				l=l*10+a[i];
			for (i=m-1; i>=0; i--)
				r=r*10+a[i];
			n=r-l;
		}
	}
	return 0;
}
