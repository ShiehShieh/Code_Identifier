#include<iostream>
#include<algorithm>
int main(){
	int x,y,cnt=0;
	scanf("%d%d",&x,&y);
	if(y%x)puts("0");
	else{
		y=y/x;
		for(int i=1;i<=y;++i)
			cnt+=(y%i==0&&std::__gcd(i,y/i)==1);
		printf("%d\n",cnt);
	}
   return 0;
}
