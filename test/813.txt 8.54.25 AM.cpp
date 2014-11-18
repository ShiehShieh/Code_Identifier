#include <stdio.h>

#define N 100

struct tree
{
	int l,r;
} a[N];

void qsort(tree a[],int l,int r)
{
	int i,j;
	tree x;
	i=l; j=r;
	x=a[l];
	while (i<j)
	{
		while (i<j&&a[j].l>=x.l)
			j--;
		if (i<j)
			a[i++]=a[j];
		while (i<j&&a[i].l<=x.l)
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
	int n,m,i;
	scanf("%d %d",&n,&m);
	for (i=0; i<m; i++)
		scanf("%d %d",&a[i].l,&a[i].r);
	qsort(a,0,m-1);
	int total,right;
	total=a[0].r-a[0].l+1;
	right=a[0].r;
	for (i=1; i<m; i++)
	{
		if (a[i].l>right)
		{
			total+=a[i].r-a[i].l+1;
			right=a[i].r;
		}
		else if (a[i].r>right)
		{
			total+=a[i].r-right;
			right=a[i].r;
		}
	}
	printf("%d\n",n-total+1);
	return 0;
}
