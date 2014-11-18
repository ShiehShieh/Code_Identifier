#include <stdio.h>

int f[1001][1001];

long min(long a,long b,long c)
{
	long k;
	k = a;
	if (b<a) k = b;
	if (c<k) k = c;
	return k;
}

int main()
{
	int ans,n,m,i,j;
	ans = 0;
	
	scanf("%d%d",&n,&m);
	for (i=0;i<=n;i++)
	{
		for (j=0;j<=n;j++)
		{
			f[i][j] = 0;
		}
	}

	for (i=1;i<=n;i++)
	{

		for (j=1;j<=m;j++)
		{
			scanf("%d",&f[i][j]);
		}
	}

	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (f[i][j] != 0)
			{
				f[i][j] = min(f[i-1][j],f[i][j-1],f[i-1][j-1])+1;
				if (f[i][j] > ans) ans = f[i][j];
			}
		}
	}

	printf("%d",ans);
   
	return 0;
}

