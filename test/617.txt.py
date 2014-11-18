#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define inf 2147483647
#define maxn 50
using namespace std;
int n,m,p,x,y,full;
struct mat
{
	long long m[maxn][maxn];
	void clean()
	{
		for (int i=0;i<=full;i++)
			for (int j=0;j<=full;j++)
				m[i][j]=0;
	}
}e,I;

mat mult(mat a,mat b)
{
	mat c;
	c.clean();
	for (int i=0;i<=full;i++)
		for (int j=0;j<=full;j++)
			for (int k=0;k<=full;k++)
				c.m[i][j]=(c.m[i][j]+(a.m[i][k]*b.m[j][k])%p)%p;
	return c;
}

mat pow(mat e,int k)
{
	mat mid=I;
	while (k)
	{
		if (k&1) mid=mult(mid,e);
		k=k>>1;
		e=mult(e,e);
	}
	return mid;
}

void dfs(int k)
{
	if (k>n)
	{
		//for (int i=n-1;i>=0;i--)
		//	cout<<((y>>i)&1);
		//cout<<' ';
		e.m[x][y]=1;
		return;
	}
	for (int i=0;i<=1;i++)
	{
		if (i==0) 
			dfs(k+1);
		else
		{
			if (((y>>(k-1))&1)||((y>>k)&1)||(k+1>n)) return ;
			int now=y;
			y=y|(1<<(k-1));
			y=y|(1<<k);
			dfs(k+2);
			y=now;
		}
	}
}

int main()
{
	scanf("%d%d%d",&m,&n,&p);
	full=(1<<n)-1;
	for (int i=0;i<=full;i++)
	{
		x=i,y=i^full;
		//for (int i=n-1;i>=0;i--)
		//	cout<<((x>>i)&1);
		//cout<<',';
		//for (int i=n-1;i>=0;i--)
		//	cout<<((y>>i)&1);
		//cout<<":  ";
		dfs(1);
		//cout<<endl;
	}
	//for (int i=1;i<=full;i++)
	//{
	//	for (int j=1;j<=full;j++) 
	//		cout<<e.m[i][j];
	//	cout<<endl;
	//}
	I.clean();
	for (int i=0;i<=full;i++) I.m[i][i]=1;
	e=pow(e,m);
	//for (int i=0;i<=full;i++)
	//{
	//	for (int j=0;j<=full;j++) 
	//		cout<<e.m[i][j]<<' ';
	//	cout<<endl;
	//}
	printf("%I64d\n",e.m[full][full]);
	return 0;
}
		
		
	
	
