#include<iostream>
int main(){
	char c[20];
	scanf("%c-%c%c%c-%c%c%c%c%c-%c",&c[0],&c[1],&c[2],&c[3],&c[4],&c[5],&c[6],&c[7],&c[8],&c[9]);
	int sum=0;
	for(int i=0;i<9;++i)sum+=(i+1)*(c[i]-'0');
	if(c[9]==sum%11+'0' || c[9]=='X'&&sum%11==10)puts("Right");
	else printf("%c-%c%c%c-%c%c%c%c%c-%c\n",c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8],sum%11==10?'X':(sum%11+'0'));
   return 0;
}
