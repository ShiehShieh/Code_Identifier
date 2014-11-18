#include<stdio.h>
#include<string.h>
#define MAXN 30
void out(unsigned long long mat[][MAXN],int n,char*desc){
	//return;
	printf("\n%s Debug:\n",desc);
	int i,j;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%lld%c",mat[i][j],j==n-1?'\n':' ');
		}
	}
	printf("\n");
}
void matmul(unsigned long long matA[][MAXN],unsigned long long matB[][MAXN],unsigned long long res[][MAXN],int ii,int ik,int ij,int mod){
	int i,j,k;
	for(i=0;i<ii;++i){
		for(j=0;j<ij;++j){
			res[i][j]=0;
			for(k=0;k<ik;++k){
				res[i][j]=(res[i][j]%mod+(matA[i][k]*matB[k][j]))%mod;
			}
		}
	}
	return;
}
void matpow(unsigned long long mat[][MAXN],int n,unsigned long long num,int mod){
	unsigned long long tm[MAXN][MAXN],res[MAXN][MAXN];
	while(!(num&1)){
		num>>=1;
		matmul(mat,mat,tm,n,n,n,mod);
		memcpy(mat,tm,MAXN*MAXN*sizeof(int));
	}
	memcpy(res,mat,MAXN*MAXN*sizeof(int));
	unsigned long long max=(-1)^((unsigned long long)(-1)>>1);
	unsigned long long cur=1;
	while(max>num)max>>=1;
	while(cur<max){
		matmul(mat,mat,tm,n,n,n,mod);
		memcpy(mat,tm,MAXN*MAXN*sizeof(int));
		cur<<=1;
		if(cur&num){
			matmul(mat,res,tm,n,n,n,mod);
			memcpy(res,tm,MAXN*MAXN*sizeof(int));
		}
	}
	memcpy(mat,res,MAXN*MAXN*sizeof(int));
	return;
}
int main(){
	unsigned long long ct[MAXN][MAXN]={0};
	int k;
	unsigned long long n;
	scanf("%d%llu",&k,&n);
	for(int i=0;i<k;++i){
		if(i)ct[i][i-1]=1;
		ct[i][k-1]=1;
	}
	unsigned long long st[1][MAXN]={1};
	matpow(ct,k,n,7777777);
	printf("%llu\n",ct[k-1][k-1]);
} 

