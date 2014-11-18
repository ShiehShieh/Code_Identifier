#include<iostream>
#include<algorithm>
#define MAXNUM 10000
int a[MAXNUM];
int main(){
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	std::sort(a,a+n);
	for(int i=0;i<n;++i)
		if(i==0||a[i]!=a[i-1])++cnt;
	printf("%d\n",cnt);
	for(int i=0;i<n;++i)
		if(i==0||a[i]!=a[i-1])
			printf("%s%d",i==0?"":" ",a[i]);
	putchar('\n');
   return 0;
}

