#include<iostream>
using namespace std;
const int N=110;
int n,i,j,sum;
int d[N],l[N],r[N];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&d[i]);
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=1;j<i;j++) if(d[i]>d[j]) 
		{
			if(sum<l[j]) sum=l[j];
		}
		l[i]=sum+1;
	}
	for(i=n;i>0;i--)
	{
		sum=0;
		for(j=n;j>i;j--) if(d[i]>d[j]) 
		{
			if(sum<r[j]) sum=r[j];
		}
		r[i]=sum+1;
	}
	for(sum=0,i=1;i<=n;i++) if(l[i]+r[i]>sum) sum=l[i]+r[i];
	printf("%d\n",n-sum+1);
	return 0;
}
