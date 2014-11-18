#include <iostream>
using namespace std;

int n;
int h[201][201];
int num[201];
int sed[201];
int out;
int p;
void getnum(int j)
{
	if(sed[j])return;
	sed[j]=1;
	for(int i=1;i<=n;i++)
	{
		if(!h[j][i])continue;
		getnum(i);
	}
	num[++p]=j;
	return;
}
void getout(int j)
{
	sed[num[j]]=1;
	for(int i=1;i<=n;i++)
	{
		if(sed[num[i]])continue;
		if(!h[num[i]][num[j]])continue;
		getout(i);
	}
}
int main()
{
	memset(h,0,sizeof(h));
	out=0;
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		while(true)
		{
			int j;
			cin>>j;
			if(j==0)break;
			h[i][j]=1;
		}
	}
	memset(sed,0,sizeof(sed));
	memset(num,0,sizeof(num));
	p=0;
	for(int i=1;i<=n;i++)
	{
		getnum(i);
	}
	memset(sed,0,sizeof(sed));
	p=0;
	for(int i=n;i>=1;i--)
	{
		if(!sed[num[i]])p++;
		getout(i);
	}
	cout<<p<<endl;
	return 0;
}


