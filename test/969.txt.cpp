#include <stdio.h>

const long size=700;
long height[size+2][size+2];
long step[size][size];
long r,c,i,j,temp,maxpath;

bool bottom(long i,long j)
{
	if (height[i][j]<=height[i+1][j]||height[i+1][j]==-1)
		if (height[i][j]<=height[i-1][j]||height[i-1][j]==-1)
			if (height[i][j]<=height[i][j+1]||height[i][j+1]==-1)
				if (height[i][j]<=height[i][j-1]||height[i][j-1]==-1)
					return true;
	return false;
}

long findpath(long i,long j)
{
	long e=0,w=0,n=0,s=0,maxs=0;
	if (!(bottom(i,j)))
	{
		if (step[i-1][j-1]!=-1)
			return step[i-1][j-1];
		else
		{
			if (height[i+1][j]>0&&height[i][j]>height[i+1][j])
			{
				findpath(i+1,j);
				s=step[i][j-1]+1;
			}
			if (height[i-1][j]>0&&height[i][j]>height[i-1][j])
			{
				findpath(i-1,j);
				n=step[i-2][j-1]+1;
			}
			if (height[i][j+1]>0&&height[i][j]>height[i][j+1])
			{
				findpath(i,j+1);
				e=step[i-1][j]+1;
			}
			if (height[i][j-1]>0&&height[i][j]>height[i][j-1])
			{
				findpath(i,j-1);
				w=step[i-1][j-2]+1;
			}
			if (e>=w&&e>=n&&e>=s)
				maxs=e;
			if (w>=e&&w>=s&&w>=n)
				maxs=w;
			if (n>=e&&n>=w&&n>=s)
				maxs=n;
			if (s>=e&&s>=w&&s>=n)
				maxs=s;
			step[i-1][j-1]=maxs;
			return step[i-1][j-1];
		}
	}
	else
	{
		step[i-1][j-1]=1;
		return step[i-1][j-1];
	}
}


int main()
{
	//FILE * f;
	//f=fopen("cin.txt","r");
	scanf("%d%d",&r,&c);
	for (i=0;i<=r+1;i++)
	{
		for (j=0;j<=c+1;j++)
		{
			if (i==0||i==r+1||j==0||j==c+1)
				height[i][j]=-1;
			else
				scanf("%d",&height[i][j]);
		}
	}
	for (i=0;i<r;i++)
		for (j=0;j<c;j++)
			step[i][j]=-1;

	temp=0;
	maxpath=1;
	for (i=1;i<=r;i++)
	{
		for (j=1;j<=c;j++)
		{
			if (height[i][j]>height[i+1][j]&&height[i][j]>height[i-1][j]&&height[i][j]>height[i][j+1]&&height[i][j]>height[i][j-1])
			{
				temp=findpath(i,j);
				if (temp>maxpath)
					maxpath=temp;
			}
		}
	}


	printf("%d\n",maxpath);
	return 0;
}
