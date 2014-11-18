#include <stdio.h>

#define max(a,b) (a>b?a:b)

//using namespace std;

int** inc = NULL;
int** map = NULL;

int move(int i, int j)
{
	if(map[i][j] == 0)
	{
		if(inc[i][j] > inc[i+1][j])
			map[i][j] = max(move(i+1, j), map[i][j]);
		if(inc[i][j] > inc[i][j+1])
			map[i][j] = max(move(i, j+1), map[i][j]);
		if(inc[i][j] > inc[i-1][j])
			map[i][j] = max(move(i-1, j), map[i][j]);
		if(inc[i][j] > inc[i][j-1])
			map[i][j] = max(move(i, j-1), map[i][j]);
		map[i][j]++;
	}
	return map[i][j];
}

int main()
{
	int x,y,i,j;
	scanf("%d%d", &x, &y);
	inc = new int*[x + 2];
	map = new int*[x + 2];	
	for(i=0; i<x+2; i++)
	{
		inc[i] = new int[y + 2];
		map[i] = new int[y + 2];
	}

	for(i=0; i<x+2; i++)
	{
		inc[i][0] = inc[i][y+1] = 100000;
	}
	for(j=0; j<y+2; j++)
	{
		inc[0][j] = inc[x+1][j] = 100000;
	}
	for(i=0; i<x+2; i++)
	{
		for(j=0; j<y+2; j++)
		{
			map[i][j] = 0;
		}
	}


	for(i=1; i<x+1; i++)
	{
		for(j=1; j<y+1; j++)
		{
			scanf("%d", &inc[i][j]);
		}
	}

	int maxVal = 1;
	for(i=1; i<x+1; i++)
	{
		for(j=1;j<y+1; j++)
		{
			if(map[i][j] == 0)
			{
				maxVal = max(maxVal, move(i, j));
			}
		}
	}
	
	printf("\n%d\n", maxVal);
	return 0;
}

