#include<iostream>
#define MAXNUM 50
#define MAXK 8
#define BASE 10
struct bignum{
	char a[50],ln;
	void fill(char *c,int x,int y){ln=0;for(int i=x;i<y;++i)a[ln++]=c[i];}
	void clear(int ll){for(int i=0;i<ll;++i)a[i]=0,ln=1;}
	inline char &operator[](int in){return a[in];}
}dp[MAXNUM][MAXK]={},tmp={},cm;
inline int max(int a,int b){return a>b?a:b;}
void cross(bignum &a,bignum &b,bignum &c){
	c.clear(a.ln+b.ln+1);
	c.ln=a.ln+b.ln-1;
	for(int i=0;i<a.ln;++i)
		for(int j=0;j<b.ln;++j)
			c[i+j]+=a[i]*b[j];
	for(int i=0;i<c.ln;++i)
		c[i+1]+=c[i]/BASE,c[i]%=BASE;
	if(c[c.ln])++c.ln;
}
char cmp(bignum &a,bignum &b){
	if(a.ln^b.ln)return a.ln<b.ln?-1:1;
	for(int i=a.ln;i>=0;--i)
		if(a[i]^b[i])return a[i]<b[i]?-1:1;
	return 0;
}
void show(bignum &a){
	for(int i=a.ln-1;i>=0;--i)printf("%d",a[i]);
	putchar('\n');
}
char inp[MAXNUM]={};
int main(){
	int n,m;
	scanf("%d%d",&n,&m),++m;
	getchar();
	for(int i=0;i<n;++i)
		inp[n-i-1]=getchar()-'0';
	for(int i=0;i<n;++i)
		dp[i][0].fill(inp,0,i+1);
	for(int k=1;k<m;++k){
		for(int i=k;i<n;++i){
			cm.ln=0;
			for(int j=i;j<n;++j){
				cm[cm.ln++]=inp[j];
				//printf("%d %d==>",j,k);
				//show(cm);printf(" * ");show(dp[i-1][k-1]);
				cross(dp[i-1][k-1],cm,tmp);
				if(cmp(tmp,dp[j][k])>0)dp[j][k]=tmp;
			}
		}
		//for(int i=k;i<n;++i)printf("%d %d=>",i,k),show(dp[i][k]);
	}
	show(dp[n-1][m-1]);
   return 0;
}
