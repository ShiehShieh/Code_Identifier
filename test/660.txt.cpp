#include<iostream>
int main(){
	int n,sum=1,i;
	scanf("%d",&n);
	for(i=1;1;sum+=i++)
		if(sum<=n && n<sum+i)
			break;
	n-=sum;
	if(i&1)
		printf("%d/%d\n",i-n,n+1);
	else
		printf("%d/%d\n",n+1,i-n);
   return 0;
}

