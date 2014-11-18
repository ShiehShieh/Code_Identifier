#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn=2005;
int n,m,best1=0,best2=0;
int up[maxn][maxn],left[maxn][maxn],right[maxn][maxn],l[maxn],r[maxn];
bool map[maxn][maxn];

inline int min(int a,int b)
{
	return a<b ? a:b;
}

void update(int& best,int num)
{
	if(num > best) best = num;
}

int main()
{
	int i,j,k;

	scanf("%d%d",&n,&m);
	for(i=1; i<=n; ++i)
		for(j=1; j<=m; ++j)
			scanf("%d",&map[i][j]);
	for(i=1; i<=n; ++i)
	{
		map[i][0]=!map[i][1];
		map[i][m+1]=!map[i][m];
	}
	for(i=1; i<=m; ++i) map[0][i]=!map[1][i];

	for(i=1; i<=m; ++i)
	{
		up[1][i] = 1;
		if(map[1][i]==map[1][i-1]) left[1][i] = 1; else left[1][i] = left[1][i-1]+1;
	}
	for(i=m; i>=1; --i)
	{
		if(map[1][i]==map[1][i+1]) right[1][i]=1; else right[1][i] = right[1][i+1]+1;
		update(best1,left[1][i]+right[1][i]-1);
	}

	best2 = 1;
	for(i=2; i<=n; ++i)
	{
		l[0]=0;
		for(j=1; j<=m; ++j)
		{
			if(map[i][j]==map[i][j-1]) l[j]=1; else l[j]=1+l[j-1];
			if(map[i][j]==map[i-1][j])
			{
				up[i][j]=1;
				left[i][j] = l[j];
			}
			else
			{
				up[i][j]=up[i-1][j]+1;
				left[i][j] = min(left[i-1][j],l[j]);
			}
		}
		r[m+1]=0;
		for(j=m; j>=1; --j)
		{
			if(map[i][j]==map[i][j+1]) r[j]=1; else r[j]=1+r[j+1];
			if(up[i][j]==1) right[i][j]=r[j]; else right[i][j]=min(right[i-1][j],r[j]);
			update(best1,up[i][j]*(left[i][j]+right[i][j]-1));
			update(best2,min(up[i][j],left[i][j]+right[i][j]-1));
		}
	}
	printf("%d\n%d\n",best2*best2,best1);
	return 0;
}


