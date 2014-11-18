#include<iostream>
#include<cmath>
inline char fc(double a,double b){return fabs(a-b)<1e-12?0:(a<b?-1:1);}
double a,b,c,d;
inline double f(double x){return a*x*x*x+b*x*x+c*x+d;}
double bs(double x,double y){
	double mid,p=f(x),r;
	if(fc(p,0)==0)return x;
	if(fc(p*f(y),0)>=0)return 1e4;
	while(x+1e-4<y){
		mid=(x+y)/2;
		r=f(mid);
		if(fc(r*p,0)<0)y=mid;
		else x=mid,p=r;
	}
	return x;
}
int main(){
	int cnt=0;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(double i=-100,v;i<=101;i+=1.00){
		v=bs(i,i+0.999);
		if(fc(v,1e4))printf("%s%.2lf",cnt++?" ":"",v);
	}
	putchar('\n');
   return 0;
}
