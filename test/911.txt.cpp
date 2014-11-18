#include <iostream>
using namespace std;
int main()
{
	int m,n,i,j,mid,k;
	int distance[302];
	//cost[i][j]记录所有在i到j村庄中，建1个邮局的最小代价
	int cost[302][302];
	//opt[i][j]记录把前i个邮局建到前j个村庄中的最优解	
	int opt[302][302];
	cin>>m>>n;
	for(i=1;i<=m;i++)
		cin>>distance[i];
	//计算cost
	for(i=1;i<=m;i++)
		for(j=i;j<=m;j++)
		{
			cost[i][j] = 0;
			mid = (i+j)/2;
			for(k=i;k<=j;k++)
				cost[i][j] += (distance[mid]-distance[k])>=0?distance[mid]-distance[k]:distance[k]-distance[mid];
		}
	//初始化opt
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			opt[i][j] = 3000000;

	opt[0][0] = 0;

	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			if(opt[i][j]<3000000)
			{
				for(k=1;j+k<=m;k++)
				{
					if(opt[i+1][j+k]>opt[i][j]+cost[j+1][j+k])
					{
						opt[i+1][j+k] = opt[i][j]+cost[j+1][j+k];
					}
				}
			}
	cout<<opt[n][m];
}

