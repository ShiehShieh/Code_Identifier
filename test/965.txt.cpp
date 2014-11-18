#include <iostream>
#include <algorithm>
#define MAX 32001
using namespace std;
int dp[62][MAX];
struct node
{
	int v;
	int m;
	int pathm[3];
	int pathv[3];
	int pathk;
}data[62];
bool comp(node a,node b)
{
	return a.m>b.m;
}
int GetMax(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int N,m,i,j;
	while(scanf("%d%d",&N,&m)!=EOF)
	{
		for(i=1;i<=m;i++)
		{
			data[i].pathk=0;
			for(j=0;j<3;j++)
			{	
				data[i].pathm[j]=0;
				data[i].pathv[j]=0;
			}
		}
		int v,p,q,mm;
		i=1,mm=1;  //mm统计主件个数
		while(i<=m)
		{
			scanf("%d%d%d",&v,&p,&q);
			if(q==0)
			{
				data[i].v=v;
				data[i].m=p*v;
				mm++; 
			}
			else  //是附件
			{
				data[i].m=0;
				data[q].pathk++;
				data[q].pathm[data[q].pathk]=v*p;
				data[q].pathv[data[q].pathk]=v;
			}
			i++;
		}
		mm--;  //多加了一个
		sort(data+1,data+m+1,comp);
		//for(i=1;i<=m;i++)
	    //	printf("%d %d %d %d %d %d\n",data[i].m,data[i].v,data[i].pathm[1],data[i].pathv[1],data[i].pathm[2],data[i].pathv[2]);
		//printf("%d\n",mm);
		for(i=1;i<=N;i++)
		{
			if(i>=(data[mm].v+data[mm].pathv[1]+data[mm].pathv[2]))
				dp[mm][i]=data[mm].m+data[mm].pathm[1]+data[mm].pathm[2];
			else if(i>=(data[mm].v+data[mm].pathv[1]))
				dp[mm][i]=data[mm].m+data[mm].pathm[1];
			else if(i>=(data[mm].v+data[mm].pathv[2]))
				dp[mm][i]=data[mm].m+data[mm].pathm[2];
			else if(i>=data[mm].v)
				dp[mm][i]=data[mm].m;
			else
				dp[mm][i]=0;
		}
		for(i=mm-1;i>=1;i--)
			for(j=1;j<=N;j++)
			{
				dp[i][j]=dp[i+1][j];
				if(j>=(data[i].v+data[i].pathv[1]+data[i].pathv[2]))
					dp[i][j]=GetMax(dp[i][j],dp[i+1][j-data[i].v-data[i].pathv[1]-data[i].pathv[2]]+data[i].m+data[i].pathm[1]+data[i].pathm[2]);
			    if(j>=(data[i].v+data[i].pathv[1]))
					dp[i][j]=GetMax(dp[i][j],dp[i+1][j-data[i].v-data[i].pathv[1]]+data[i].m+data[i].pathm[1]);
				if(j>=(data[i].v+data[i].pathv[2]))
					dp[i][j]=GetMax(dp[i][j],dp[i+1][j-data[i].v-data[i].pathv[2]]+data[i].m+data[i].pathm[2]);
				if(j>=data[i].v)
					dp[i][j]=GetMax(dp[i][j],dp[i+1][j-data[i].v]+data[i].m);
			}
		printf("%d\n",dp[1][N]);
	}
	return 0;
}
