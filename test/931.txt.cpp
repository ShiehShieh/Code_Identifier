#include <stdio.h>

int main()
{
	int hi,an;
	int sz[10];
	for (int a=0; a<10; ++a)
	{
		scanf("%d",&sz[a]);
	}
	scanf("%d",&hi);
	an=0;
	for (int a=0; a<10; ++a)
	{
		if (sz[a]<=hi+30)
		{
			an=an+1;
		}
	}
	printf("%d",an);
	return 0;
}
