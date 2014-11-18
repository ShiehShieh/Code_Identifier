#include <cstdio>

int main()
{
	unsigned int n;
	scanf("%u",&n);
	printf("%u\n",((n<<16)|(n>>16)));
	return 0;
}
