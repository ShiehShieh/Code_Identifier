#include<stdio.h>
#include<string.h>
int main()
{
	int n,a[100],i,j,b[100],c[100],max=0;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{ 
		scanf("%d",&a[i]);
		b[i]=1;c[i]=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
			if(a[i]>a[j]&&b[j]+1>b[i])
				b[i]=b[j]+1;
	}
	for(i=n-1;i>=0;i--)
	{
		for(j=n-1;j>i;j--)
			if(a[i]>a[j]&&c[j]+1>c[i])
				c[i]=c[j]+1;
	}
	for(i=0;i<n;i++)
		if(b[i]+c[i]>max)
		{
			max=b[i]+c[i];
		}

printf("%d\n",n-max+1);	
return 0;	
}
