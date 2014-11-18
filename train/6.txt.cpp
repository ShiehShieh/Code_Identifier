#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
///////////////////////////////////////////////////////////////////////////
struct square{
	long x;
	long y;
};
///////////////////////////////////////////////////////////////////////////
long n;
long m;
short k;
square avl[1000];
short dp[1000];
double ans;
///////////////////////////////////////////////////////////////////////////
inline int cmp(const void*a,const void*b){
	const square*A=(square*)a;
	const square*B=(square*)b;
	return A->x+A->y-B->x-B->y;
}
///////////////////////////////////////////////////////////////////////////
void init(){
	cin>>n>>m>>k;
	for(short i=0;i<k;++i)cin>>avl[i].x>>avl[i].y;
	qsort(avl,k,sizeof(square),cmp);
}
///////////////////////////////////////////////////////////////////////////
void work(){
	for(short i=k-1;i>=0;--i){
		dp[i]=1;
		for(short j=i+1;j<k;++j)
			if(avl[i].x<avl[j].x&&avl[i].y<avl[j].y)dp[i]=max((int)dp[i],dp[j]+1);
	}
	short t=0;
	for(short i=0;i<k;++i)t=max(t,dp[i]);
	ans=(sqrt(2.)*t+n+m-(t<<1))*100;
}
///////////////////////////////////////////////////////////////////////////
void print(){
	cout.flags(ios::fixed);
	cout.precision(0);
	cout<<ans<<endl;
}
///////////////////////////////////////////////////////////////////////////
int main(){
	init();
	work();
	print();
	return 0;
}

