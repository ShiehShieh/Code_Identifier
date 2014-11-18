#include<stdio.h>
unsigned long n;
int main()
{
scanf("%lu",&n);
printf("%lu\n",((n<<16)|(n>>16)));
return 0;
}

