#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int n;
	int sz[10002],q1[10002];
	int ans;

	scanf("%d",&n);
	memset(sz,0,sizeof(sz));
	memset(q1,0,sizeof(q1));
	for (int i=0; i<n; ++i)
	{
		scanf("%d",&sz[i]);
	}
	int h1=0;
	int h2=0;
	int t1=n;
	int t2=0;
	sort(sz,sz+n);
	ans=0;
	int now,now2;
	int f;
	for (int i=0; i<n-1; ++i)
	{
		f=0;
		if ((sz[h1]>=q1[h2])&&(q1[h2]!=0)&&(f==0))
		{			
			now=q1[h2];
			h2++;
			f=1;
		}
		if ((sz[h1]<=q1[h2])&&(sz[h1]!=0)&&(f==0))
		{	
			now=sz[h1];	
			h1++;
			f=1;
		}
		if ((q1[h2]==0)&&(f==0))
		{
			now=sz[h1];	
			h1++;
			f=1;
		}
		if ((sz[h1]==0)&&(f==0))
		{
			now=q1[h2];	
			h2++;
			f=1;
		}
		
		f=0;
		if ((sz[h1]>=q1[h2])&&(q1[h2]!=0)&&(f==0))
		{			
			now2=q1[h2];
			h2++;
			f=1;
		}
		if ((sz[h1]<=q1[h2])&&(sz[h1]!=0)&&(f==0))
		{	
			now2=sz[h1];	
			h1++;
			f=1;
		}
		if ((q1[h2]==0)&&(f==0))
		{
			now2=sz[h1];	
			h1++;
			f=1;
		}
		if ((sz[h1]==0)&&(f==0))
		{
			now2=q1[h2];	
			h2++;
			f=1;
		}

		ans+=now+now2;
		q1[t2]=now+now2;
		t2++;
	}
	printf("%d\n",ans);
}

