#include<iostream>
int main(){
	int n,k,sum=0;
	scanf("%d%d",&n,&k);
	for(int p=1;k;k/=2,p*=n)
		sum+=p*(k&1);
	printf("%d\n",sum);
   return 0;
}
