#include <stdio.h>

long long int best[101];
long long int current[101];
long long int seq;
bool mark;

void search(int depth, long long int a, long long int b);
long long int calculate(long long int a, long long int b);

int main()
{
	int a,b;
	scanf("%d%d", &a, &b);
	int depth;
	current[0]=1;
	mark=false;
	for (depth=1;;depth++)
	{
		seq=depth;
		best[seq]=10000000;
		search(depth, a, b);
		if (mark)
		{
			for (int i=1;i<=seq;i++)
				printf("%ld ", best[i]);
			printf("\n");
			break;
		}
	}
	return 0;
}

void search(int depth, long long int a, long long int b)
{
	if (depth==1)
	{
		if (a==1 && b>current[seq-depth])
		{
			current[seq]=b;
			if (current[seq]<=best[seq])
			{
				for (int i=1;i<=seq;i++)
					best[i]=current[i];
			}
			mark=true;
		}
	return;
	}
	
	long long int max=b*depth/a;
	for (long long int p=max;p>current[seq-depth];p--)
	{
		if (p>best[seq])
		{
			p=best[seq];
			continue;
		}
		if (a*p-b<=0)
			continue;
		current[seq-depth+1]=p;
		long long int m=calculate(a*p-b, b*p);
		search(depth-1, ((a*p-b)/m), ((b*p)/m));
	}
}

long long int calculate(long long int a, long long int b)
{
	while (1)
	{
		if (a<b)
		{
			long long int c=a;
			a=b;
			b=c;
		}
		if (a%b==0)
			return b;
		else
		{
			long long int c=b;
			b=a%b;
			a=c;
		}
	}
}
