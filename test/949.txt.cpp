#include<iostream>
#include<algorithm>
#define MAXNUM 2001
int cuv[2][MAXNUM]={};
template<int T>class cmp{public:inline int operator()(int a,int b){return cuv[T][a]>cuv[T][b];}};
inline int min(int x,int y){return x<y?x:y;}
int main(){
	int n,m,ro,cl,talk,p;
	int x,y,x1,y1;
	scanf("%d%d%d%d%d",&n,&m,&cl,&ro,&talk);
	while(talk--){
		scanf("%d%d%d%d",&x,&y,&x1,&y1);
		if(x==x1)cuv[1][min(y,y1)-1]++;
		else if(y==y1)cuv[0][min(x,x1)-1]++;
	}
	int a[MAXNUM]={},out[MAXNUM]={};
	for(int i=0;i<n-1;++i)a[i]=i;
	std::sort(a,a+n-1,cmp<0>());
	for(int i=0;i<cl;++i)out[i]=a[i];
	std::sort(out,out+cl);
	for(int i=0;cl--;++i)printf("%d%s",out[i]+1,cl?" ":"\n");
	
	for(int i=0;i<m-1;++i)a[i]=i;
	std::sort(a,a+m-1,cmp<1>());
	for(int i=0;i<ro;++i)out[i]=a[i];
	std::sort(out,out+ro);
	for(int i=0;ro--;++i)printf("%d%s",out[i]+1,ro?" ":"\n");
   return 0;
}

