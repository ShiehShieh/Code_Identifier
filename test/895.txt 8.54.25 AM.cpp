#include <stdio.h>
int gcd(int a,int b)
{
	if (b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a % b);
	}
}
int main()
{

	int n,t1,t2;
	scanf("%d\n",&n);
	for (int a=0; a<n; ++a)
	{
		scanf("%d %d\n",&t1,&t2);
		if ((t1==0)||(t2==0))
		{
			if (t1+t2==1)
			{
				printf("%c",'y');				
			}
			else
			{
				printf("%c",'n');
			}
			continue;
		}
		if (((t1^t2)&1==1)&&(gcd(t1,t2)==1))
		{
			printf("%c",'y');
		}
		else
		{
			printf("%c",'n');
		}
	}
	return 0;
}

