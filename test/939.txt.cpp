#include <stdio.h>
#include <iostream.h>
using namespace std;

int main()
{
	int n,b;
	int sz[1000];
	scanf("%d",&n);
	memset(sz,0,sizeof(sz));
	for (int a=0; a<n; ++a)
	{
		scanf("%d",&b);
		sz[b]=1;
	}
	int an=0;
	for (int a=0; a<1001; ++a)
	{
		if (sz[a]==1)
		{
			an=an+1;
		}
	}
	printf("%d\n",an);
	for (int a=0; a<1001; ++a)
	{
		if (sz[a]==1)
		{
			printf("%d ",a);
		}
	}
	return 0;
}

