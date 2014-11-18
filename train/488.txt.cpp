//Floyd Algorithm

#include <iostream>
#include <string.h>

using namespace std;

const long VERY_BIG_NUMBER = 10000000;

long edge[100][100];
long dist[100][100];
int prev[100][100];

int main()
{
	int x1,x2,y;
	int besti,bestj,bestk,ans;
	int n,m;//n<=100; m<=10000
	while (cin >> n >> m)
	{
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
			{
				edge[i][j] = VERY_BIG_NUMBER;
				dist[i][j] = VERY_BIG_NUMBER;
			}
		ans = VERY_BIG_NUMBER;
		besti = 0;
		bestj = 0;
		bestk = 0;
		//init;
		for (int i=0; i<m; i++)
		{
			cin >> x1 >> x2 >> y;
			x1--;
			x2--;
			if (edge[x1][x2] > y)
			{
				dist[x1][x2] = y;
				dist[x2][x1] = y;
				edge[x1][x2] = y;
				edge[x2][x1] = y;
			}
		}
		for (int i=0; i<n; i++)  //initialize the previous node for the shortest path from i to j
			for (int j=0; j<n; j++)
			    if (dist[i][j] < VERY_BIG_NUMBER) prev[i][j] = i;
				else prev[i][j] = -1;
		for (int k=0; k<n; k++) //enumeration of transitional nodes
		{
			for (int i=0; i<k; i++)
				for (int j=0; j<=k; j++)
				{
					if (i == j) continue;
					if (ans > dist[i][j] + edge[i][k] + edge[k][j])
					{
						ans = dist[i][j] + edge[i][k] + edge[k][j];
						besti = i;
						bestj = j;
						bestk = k;
					}
				}
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					if (dist[i][k] + dist[k][j] < dist[i][j]) 
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						prev[i][j] = prev[k][j];
					}
		}
		if (ans == VERY_BIG_NUMBER) cout << "No solution." << endl;
		else
		{
			cout << ans << endl;
		}
	}
	return 0;
}

