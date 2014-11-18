#include <stdio.h>

int main()
{

	char c1='0';
	char c2='0';
	char c3='0';
	for (; ;)
	{
		if ((c1>'9')||(c1<'0')) break;
		c3=c2;
		c2=c1;
		c1 = getchar();
	}
	int n=0;
	n=(c3-'0')*10+c2-'0';

	n=n%4;
	int an;
	if (n==0)
	{
		an=0;
	}
	if (n==1)
	{
		an=1;
	}
	if (n==2)
	{
		an=1;
	}
	if (n==3)
	{
		an=0;
	}
	printf("%d",an);
	return 0;
}

