#include<iostream>
#define LIMIT 10000002
char pme[LIMIT]={1,1};
int a[100]={};
int cnt=0,n,k;
void cho(int d,int x,int sum){
	if(d>=k){
		cnt+=!pme[sum];
		return;
	}
	for(int i=x;i<n;++i)
		cho(d+1,i+1,sum+a[i]);
}
int main(){
	for(int i=2;i*i<LIMIT;++i)
		if(!pme[i])
			for(int j=i*i;j<LIMIT;j+=i)
				pme[j]=1;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	cho(0,0,0);
	printf("%d\n",cnt);
   return 0;
}
