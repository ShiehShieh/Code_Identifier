#include<iostream>
#include<cmath>
#define MAXBIT 80
#define BASE 10000000
#define ln MAXBIT
struct bignum{
	int a[MAXBIT];
	inline int&operator[](int in){return a[in];}
}ap={};
long long tmp[MAXBIT*2];
void multi2(bignum &a){
	for(int i=0;i<ln;++i)a[i]*=2;
	for(int i=0;i<ln;++i)
		i<ln-1?(a[i+1]+=a[i]/BASE):1,a[i]%=BASE;
}
void multi(bignum &a,bignum &b){
	for(int i=0;i<ln;++i)tmp[i]=0;
	for(int i=0;i<ln;++i)
		for(int j=0;j<ln && i+j<ln;++j)
			tmp[i+j]+=(long long)b[i]*b[j];
	for(int i=0;i<ln;++i)
		tmp[i+1]+=tmp[i]/BASE,tmp[i]%=BASE;
	for(int i=0;i<ln;++i)a[i]=tmp[i];
}
void exp(bignum &a,int n){
	if(n==0){a[0]=1;return;}
	bignum p={};
	exp(p,n/2);
	multi(a,p);
	if(n&1)multi2(a);
}
char out[1000]={};
void show(bignum &a,char *key){
	for(int i=MAXBIT-2;i>=0;--i)
		sprintf(key,"%07d",a[i]),key+=7;
	--*(key-1);
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",int(n*log10(2.0)+1));
	exp(ap,n);
	show(ap,&out[0]);
	for(int i=strlen(out)-500,k=500;k>0;++i,--k)
		printf("%c",out[i]);
   return 0;
}
