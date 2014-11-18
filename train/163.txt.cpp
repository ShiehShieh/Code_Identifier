#include<stdio.h>
#include<string.h>
int next[32][32]={0};
#define MAXN 32
void matmul(int matA[][MAXN],int matB[][MAXN],int res[][MAXN],int ii,int ik,int ij,int mod){
    int i,j,k;
    for(i=0;i<ii;++i){
        for(j=0;j<ij;++j){
            res[i][j]=0;
            for(k=0;k<ik;++k){
                res[i][j]=(res[i][j]%mod+(matA[i][k]*matB[k][j])%mod)%mod;
            }
        }
    }
    return;
}
void matpow(int mat[][MAXN],int n,long num,int mod){
	int tm[MAXN][MAXN]={0},res[MAXN][MAXN];
    while(!(num&1)){
        num>>=1;
        matmul(mat,mat,tm,n,n,n,mod);
        memcpy(mat,tm,MAXN*MAXN*sizeof(int));
    }
    memcpy(res,mat,MAXN*MAXN*sizeof(int));
    unsigned long max=(-1)^((unsigned long)(-1)>>1);
    long cur=1;
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
void dfs(int m,int num,short cur,short max){
    int t=1<<cur;
    if(cur>=max)next[m][num]=1;
    else if(m&t)dfs(m,num,cur+1,max);
    else if(m&(t<<1))dfs(m,num|t,cur+1,max);
    else{
        dfs(m,num|t,cur+1,max);
        if(cur<max-1)dfs(m,num,cur+2,max);
    }
    return;
}
int main(){
    long n;
    int p;
    int i,j;
    int m;
    scanf("%ld%d%d",&n,&m,&p);
    const int max=1<<m;
    const int size=sizeof(int)*max;
    for(i=0;i<max;++i)dfs(i,0,0,m);
    matpow(next,max,n,p);
	printf("%d\n",next[0][0]);
    return 0;
} 
