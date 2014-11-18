#include<iostream>
#include<cstdlib>
using namespace std;
///////////////////////////////////////////////////////////////////////
short N;
long long ans;
int xx[100],xy[100],yx[100],yy[100];
int x[200],y[200];
short xn,yn;
bool pln[200][200];
///////////////////////////////////////////////////////////////////////
inline int cmp(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}
///////////////////////////////////////////////////////////////////////
void init(){
	cin>>N;
	int zx[200],zy[200];
	for(short i=0;i<N;++i){
		cin>>xx[i]>>xy[i]>>yx[i]>>yy[i];
		zx[i<<1]=xx[i];
		zx[(i<<1)+1]=yx[i];
		zy[i<<1]=xy[i];
		zy[(i<<1)+1]=yy[i];
	}
	qsort(zx,N<<1,sizeof(int),cmp);
	qsort(zy,N<<1,sizeof(int),cmp);
	x[xn]=zx[0];
	++xn;
	for(short i=1;i<N<<1;++i){
		if(zx[i]!=x[xn-1]){
			x[xn]=zx[i];
			++xn;
		}
	}
	y[yn]=zy[0];
	++yn;
	for(short i=1;i<N<<1;++i){
		if(zy[i]!=y[yn-1]){
			y[yn]=zy[i];
			++yn;
		}
	}
}
///////////////////////////////////////////////////////////////////////
void work(){
	for(short i=0;i<N;++i){
		for(short j=0;j<xn-1;++j){
			for(short k=0;k<yn-1;++k){
				if(xx[i]<=x[j]&&x[j]<yx[i]&&xy[i]<=y[k]&&y[k]<yy[i])pln[j][k]=1;
			}
		}
	}
	for(short i=0;i<xn-1;++i){
		for(short j=0;j<yn-1;++j){
			if(pln[i][j])ans+=(x[i+1]-x[i])*(long long)(y[j+1]-y[j]);
		}
	}
}
///////////////////////////////////////////////////////////////////////
int main(){
	init();
	work();
	cout<<ans<<endl;
	return 0;
}

