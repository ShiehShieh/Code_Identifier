#include<iostream>
#include<algorithm>
#define MAXNUM 1000000
#define INF 0x7f7f7f7f
int a[MAXNUM]={};
inline int guess(int p,int q){
	return p/q+(q>0?(p>0&&p%q^0):-(p>0&&p%q^0));
}
int main(){
	int n=0,p,org,u,v,con,maxi=0,pre;
	scanf("%d",&p);
	scanf("%d%d",&org,&v);
	p-=org;
	a[0]=v;
	while(scanf("%d%d",&u,&v)&&u^-1&&v^-1)a[u-org]=v,n=maxi=std::max(maxi,u-org+1);
	scanf("%d",&con);
	for(int i=maxi;a[i-1]-con>0;a[i]=a[i-1]-con,n=++i);
	pre=0;
	for(int i=1;i<n;++i)
		if(a[i]){
			for(int j=pre+1;j<i;++j){
				a[j]=a[pre]+(a[i]-a[pre])/(i-pre)*(j-pre);
			}
			pre=i;
		}

	maxi=INF;
	int mini=-INF;
	for(int i=0;i<n;++i)
		if(p^i){
			
			if(a[p]-a[i]<0)maxi=std::min(maxi, guess(i*a[i]-a[p]*p,a[p]-a[i]));
			else 			   mini=std::max(mini, guess(i*a[i]-a[p]*p,a[p]-a[i]));
			//printf("%d %d %d\n",maxi,mini,guess(i*a[i]-a[p]*p,a[p]-a[i]));
		}
	if(mini>maxi)
		puts("No Solution");
	else if(mini<=0 && 0<=maxi)
		puts("0");
	else if(mini<=0&&maxi<=0)
		printf("%d\n",std::max(mini,maxi));
	else
		printf("%d\n",std::min(mini,maxi));
   return 0;
}
