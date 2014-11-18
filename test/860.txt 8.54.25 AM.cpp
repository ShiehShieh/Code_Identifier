#include <iostream>
using namespace std;

#define N 20

const int ix[8]={1,2,2,1,-1,-2,-2,-1};
const int iy[8]={2,1,-1,-2,-2,-1,1,2};

bool f[N][N];
int g[N][N]={0};

int main()
{
	int n,m,x,y,xx,yy,i,j;
	memset(f,1,sizeof(f));
	scanf("%d %d %d %d",&n,&m,&x,&y);
	f[x][y]=false;
	for (i=0; i<8; i++)
	{
		xx=x+ix[i];
		yy=y+iy[i];
		if (xx>=0&&xx<=n&&yy>=0&&yy<=m)
			f[xx][yy]=false;
	}
	i=0;
	while (i<=n&&f[i][0])
	{
		g[i][0]=1;
		i++;
	}
	j=0; 
	while (j<=m&&f[0][j])
	{
		g[0][j]=1;
		j++;
	}
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			if (f[i][j])
				g[i][j]=g[i-1][j]+g[i][j-1];
	printf("%d\n",g[n][m]);
	return 0;
}
