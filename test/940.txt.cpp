#include <stdio.h>
#include <iostream.h>
using namespace std;

int main()
{
	__int64 n,m;
	__int64 sz[21],li[21];
	__int64 tt=0;
	scanf("%I64d %I64d",&n,&m);
	m=m-1;
	sz[0]=1;
	for (int a=1; a<=19; ++a)
	{
		sz[a]=sz[a-1]*a;
	}
	bool bl[21];
	memset(bl,0,sizeof(bl));
	__int64 s,an,r;
	for (int a=n; a>0; --a)
	{
		s=m/sz[a-1];
		m=m-s*sz[a-1];	
		s=s+1;	
		an=0;
		r=-1;
		for (int b=1; b<=n; ++b)
		{
			if (bl[b]==0)
			{
				an=an+1;
				if (an==s)
				{
					r=b;
					bl[b]=1;
					tt=tt+1;
					li[tt]=r;
					break;
				}
			}
		}
	}
	for (int a=1; a<=tt; ++a)
	{
		printf("%I64d ",li[a]);
	}

}

