#include<stdio.h>
#include<string.h>
#define MAXN 100
void out(int mat[][MAXN],int n,char*desc){
	return;
	printf("\n%s:\n",desc);
	int i,j;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%d%c",mat[i][j],j==n-1?'\n':' ');
		}
	}
	printf("\n");
}
void matmul(int matA[][MAXN],int ii,int ik,int matB[][MAXN],int ij,int res[][MAXN]){
	int i,j,k;
	for(i=0;i<ii;++i){
		for(j=0;j<ij;++j){
			res[i][j]=0;
			for(k=0;k<ik;++k){
				res[i][j]+=matA[i][k]*matB[k][j];
			}
		}
	}
	return;
}
int main(){
	int n,m;
	unsigned long k;
	unsigned max=~(((unsigned)-1)>>1),cur=1;
	int i,j,t;
	int tm[MAXN][MAXN],last[MAXN][MAXN]={{0}},ct[MAXN][MAXN]={0},res[MAXN][MAXN];
	scanf("%d%d%ld",&n,&m,&k);
	long count=k/m,mod=k%m;
	while(count&&!(max&count))max>>=1;
	for(i=0;i<n;++i)ct[i][i]=1;
	for(i=0;i<m;++i){
		memset(tm,0,MAXN*MAXN*sizeof(int));
		for(j=0;j<n;++j){
			scanf("%d",&t);
			tm[t-1][j]=1;
		}
		matmul(ct,n,n,tm,n,res);
		memcpy(ct,res,MAXN*MAXN*sizeof(int));
		if(i==mod-1){
			memcpy(last,res,MAXN*MAXN*sizeof(int));
		}
	}
	out(ct,n,"ct");
	if(count){
		if(1){
			while(!(count%2)){
				count/=2;
				matmul(ct,n,n,ct,n,tm);
				memcpy(ct,tm,MAXN*MAXN*sizeof(int));
			}
			memcpy(res,ct,MAXN*MAXN*sizeof(int));
			while(cur<max){
				matmul(ct,n,n,ct,n,tm);
				memcpy(ct,tm,MAXN*MAXN*sizeof(int));
				cur<<=1;
				if(cur&count){
					matmul(ct,n,n,res,n,tm);
					memcpy(res,tm,MAXN*MAXN*sizeof(int));
				}
			}
			memcpy(ct,res,MAXN*MAXN*sizeof(int));
		}
	}
	else{
		memset(ct,0,MAXN*MAXN*sizeof(int));
		for(i=0;i<n;++i)ct[i][i]=1;
	}
	out(ct,n,"ct^n");
	if(mod){
		matmul(ct,n,n,last,n,tm);
		memcpy(ct,tm,MAXN*MAXN*sizeof(int));
	}
	int num[1][MAXN];
	for(i=0;i<n;num[0][i]=i+++1);
	matmul(num,1,n,ct,n,res);
	for(i=0;i<n;++i){
		printf("%d%c",res[0][i],i==n-1?'\n':' ');
	}
	return 0;
}
