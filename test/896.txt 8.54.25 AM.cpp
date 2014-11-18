#include <stdio.h>
__int64 an;
void gcd(__int64 a,__int64 b)
{
	if (b==0)
	{
	}
	else
	{
		an=an+(a/b)*b;
		gcd(b,a % b);
	}
}
int main()
{
	__int64 n,t1,t2;
	n=10;
	for (__int64 a=0; a<n; ++a)
	{
		scanf("%I64d %I64d\n",&t1,&t2);
		an=0;
		gcd(t1,t2);
		printf("%I64d\n",an);
	}
	return 0;
}

