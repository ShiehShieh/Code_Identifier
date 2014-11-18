#include<iostream>
#define MAGIC 60
#define SPEED 17
#define COST 10
#define REVI 4
#define MAXNUM 300010
#define INF 0x7f7f7f7f
int dp[MAXNUM][COST]={}; 
inline int max(int a,int b){return a>b?a:b;}
int main(){
	int m=0,dis=0,limit=0,t=0,mp,dv;
	int tp;
	int ys=INF,no=-1;
	scanf("%d%d%d",&m,&dis,&limit);
	for(int i=0;i<=limit;++i){//i = maketime
		t=limit-i;
		mp=m+i*REVI;
		dv=dis;
		if(dv>mp/COST*MAGIC && t>mp/COST){//tp = magictime
			tp=mp/COST;
			dv-=tp*MAGIC;
			t-=tp;
			mp%=COST;
			if(t>=(dv+SPEED-1)/SPEED)ys<?=i+tp+(dv+SPEED-1)/SPEED;
			else no>?=tp*MAGIC+t*SPEED;
		}else if(dv>mp/COST*MAGIC && t<=mp/COST)no>?=t*MAGIC;
		else{
			if(t<(dv+MAGIC-1)/MAGIC)no>?=t*MAGIC;
			else ys<?=(dv+MAGIC-1)/MAGIC+i;
		}
	}
	if(ys!=INF)printf("Yes\n%d\n",ys);
	else printf("No\n%d\n",no);
   return 0;
}
