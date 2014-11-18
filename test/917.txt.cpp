#include<iostream>
#define MAXNUM 100000
char bo[MAXNUM]={};
int main(){
	int n,m,u,v,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		for(int j=u;j<=v;++j)
			bo[j]=1;
	}
	for(int i=0;i<=n;++i)
		cnt+=!bo[i];
	printf("%d\n",cnt);
   return 0;
}
