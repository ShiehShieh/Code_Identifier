#include<iostream>
int main(){
	int n,i;
	scanf("%d",&n);
	double p=0;
	for(i=1;p<=(double)n;p+=(double)1/i++);
	printf("%d\n",i-1);
   return 0;
}
