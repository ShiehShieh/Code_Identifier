#include<math.h>
#include<stdio.h>
main()
{
long sum,n=0;
scanf("%ld",&sum);
while((1+n*n)/2<=sum)n++;
for(n--;n>=2;n--)
{
if((2*sum-n*n-n)%(2*n)==0)printf("%d %d\n\n",(2*sum+1-n*n)/(2*n)+1,((2*sum+1-n*n)/(2*n))+n);
}
} 

