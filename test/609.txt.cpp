#include<iostream>
using namespace std;
__int64 dp(int *a,int n)
{
	int i;
	__int64 max,sum;
	max=sum=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>0)sum+=a[i];
		else sum=0;
		if(sum>max)max=sum;
	}
	return max;
}
int main()
{
	__int64 max,sum;
	int n,m,i,j,k,x;
	int a[300][300],b[300];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)a[i][j]=-32000;
		}
		sum=max=0;
		for(i=0;i<n;i++)
		{
			memset(b,0,sizeof(b));
			for(j=i;j<n;j++)
			{
				
				for(k=0;k<=m;k++)
				{
						b[k]+=a[j][k];
				}
				sum=dp(b,m);
				if(sum>max)max=sum;
				
			}
		}
			
			printf("%I64d\n",max);
			return 0;
}
