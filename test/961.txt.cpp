#include<iostream>
#include<algorithm>
int base;
struct bignum{
	int a[70],ln;
	inline int&operator[](int in){return a[in];}
};
int p[70];
void add(bignum &a){
	a[a.ln]=0;
	for(int i=0;i<a.ln;++i)p[i]=a[i];
	for(int i=0;i<a.ln;++i)
		a[i]=p[i]+p[a.ln-1-i];
	for(int i=0;i<a.ln;++i)
		a[i+1]+=a[i]/base,a[i]%=base;
	if(a[a.ln])++a.ln;
}
void show(bignum &a){
	for(int i=a.ln-1;i>=0;--i)
		printf("%c",(a[i]<=9)?(a[i]+'0'):(a[i]+'A'-10));
	putchar('\n'); 
}
char check(bignum &a){
	int i=0;
	for(i=0;i<a.ln/2;++i)if(a[i]^a[a.ln-1-i])return 0;
	return 1;
}
char inp[1000];
bignum bc={};
int main(){
	scanf("%d",&base);getchar();
	gets(inp);
	for(int i=strlen(inp)-1;i>=0;--i)
		bc[bc.ln++]=inp[i]>='A'?inp[i]-'A'+10:inp[i]-'0';
	int step;
	for(step=0;step<31;++step){
		if(check(bc))break;
		add(bc);
	}if(step>=31)puts("Impossible!");
	else printf("STEP=%d\n",step);
   return 0;
}

