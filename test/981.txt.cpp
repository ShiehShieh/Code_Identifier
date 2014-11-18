#include<iostream>
#include<algorithm>
#include<cmath>
#define MAXNUM 200
inline char fc(double a,double b){return (fabs(a-b)<1e-6)?0:(a<b?-1:1);}
struct node_t{double x,ct;int n;}node[MAXNUM*2],heap[MAXNUM*2];
class cmp{public:inline bool operator()(node_t a,node_t b){return a.x<b.x;}};
class hmp{public:inline bool operator()(node_t a,node_t b){return a.ct>b.ct;}};
int n,exist[MAXNUM]={},hpsize=0,si=0;
inline double min(double a,double b){return fc(a,b)<0?a:b;}
int main(){
	double x=0,cost,sum=0;
	double con,dis,unit;
	scanf("%lf%lf%lf%lf%d",&dis,&con,&unit,&cost,&n);
	node[si].x=x, node[si].n=0, node[si++].ct=cost;
	node[si].x=min(x+con*unit,dis),node[si].n=0, node[si++].ct=-1;
	for(int i=0;i<n;++i){
		scanf("%lf%lf",&x,&cost);
		node[si].x=x, node[si].n=i+1 , node[si++].ct=cost;
		node[si].x=min(x+con*unit,dis), node[si].n=i+1 , node[si++].ct=-1;
	}
	std::sort(node,node+si,cmp());
	double pre=0,now;
	for(int i=0;i<si;){
		now=node[i].x,dis;
		if(!hpsize&&i!=0){sum=-1;break;}
		else sum+=(now-pre)*heap[0].ct/unit;
		for(;fc(node[i].x,now)==0 && i<si;++i){
			if(fc(node[i].ct,-1)!=0)heap[hpsize++]=node[i],std::push_heap(heap,heap+hpsize,hmp());
			else exist[node[i].n]=1;
		}
		while(exist[heap[0].n] && hpsize>0)std::pop_heap(heap,heap+hpsize--,hmp());
		pre=now;
	}
	if(fc(pre,dis)!=0||fc(sum,-1)==0)puts("-1");
	else printf("%.2lf\n",sum);
   return 0;
}
