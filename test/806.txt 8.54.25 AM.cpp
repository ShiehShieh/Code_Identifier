#include<iostream>
#define BASE 10000000
struct bignum{
	int a[30],ln;
	inline int&operator[](int in){return a[in];}
}sum={};
void cross(bignum &a,int p){
	for(int i=0;i<a.ln;++i)a[i]*=p;
	for(int i=0;i<a.ln;++i)
		a[i+1]+=a[i]/BASE,a[i]%=BASE;
	if(a[a.ln])++a.ln;
}
void show(bignum &a){
	printf("%d",a[a.ln-1]);
	for(int i=a.ln-2;i>=0;--i)printf("%07d",a[i]);
	putchar('\n');
}
int turn[10][10]={},tn[10]={};
int main(){
	int n=10,m;
	sum.ln=sum[0]=1;
	char s[200];
	scanf("%s%d",s,&m);
	for(int i=0;i<n;++i)turn[i][i]=1;
	for(int i=0,u,v;i<m;++i){
		scanf("%d%d",&u,&v);
		turn[u][v]=1;
	}
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				turn[i][j]|=turn[i][k]&turn[k][j];
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			tn[i]+=turn[i][j];
	for(int i=0;s[i];++i)cross(sum,tn[s[i]-'0']);
	show(sum);
   return 0;
}
