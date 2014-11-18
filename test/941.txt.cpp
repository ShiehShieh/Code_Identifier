#include<iostream>
#define LIMIT 300
int cnt[LIMIT]={};
int find(int x){
	for(int i=x;i>=0;--i)if(cnt[i])return i;
	return -1;
}
int main(){
	int w,n,cu=0;
	scanf("%d%d",&w,&n);
	for(int i=0,u;i<n;++i)
		scanf("%d",&u),++cnt[u];
	for(int i=w,t;i>=0;--i)
		while(cnt[i]){
			--cnt[i];++cu;
			if((t=find(w-i))!=-1)--cnt[t];
		}
	printf("%d\n",cu);
   return 0;
}

