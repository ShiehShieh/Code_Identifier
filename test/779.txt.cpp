#include <iostream>
using namespace std;
int rec[50001],a[317];
int main()
{
	int n,count=1,i=0;
	cin>>n;
	rec[0]=0;
	a[0]=1;
	for(int i=1;i<317;i++)
	{
		a[i]=(a[i-1]*2)%10000;
	}
	while(1)
	{
		for(int j=0;j<i+1;j++)
		{
			rec[count]=(rec[count-1]+a[i])%10000;
			if(++count==n+1)
			{
				cout<<rec[count-1];
				return 0;
			}
		}
		i++;
	}
	return 0;
}


