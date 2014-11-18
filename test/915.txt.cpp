#include<iostream>
int a[20];
int main(){
	int n=10,hi,cnt=0;
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	scanf("%d",&hi);
	for(int i=0;i<n;++i)cnt+=(hi+30>=a[i]);
	printf("%d\n",cnt);
   return 0;
}

