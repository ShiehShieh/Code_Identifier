#include <stdio.h>

#define MAXN 510
#define inf 1000000000
typedef int elem_t;

inline elem_t max(elem_t a,elem_t b)
{
	return a>b?a:b;
}

inline elem_t min(elem_t a,elem_t b)
{
	return a<b?a:b;
}

elem_t prim2nd(int n,elem_t mat[][MAXN],int* pre,int& sum){
	elem_t curmin[MAXN],dis[MAXN][MAXN],ret;
	int v[MAXN],i,j,k;
	bool found = false;
 
	for (i=0;i<n;i++)
		curmin[i]=inf,v[i]=0,pre[i]=-1;
	for (i=0;i<n;i++)
       for (j=0;j<n;j++)
		  dis[i][j] = 0;
	for (sum=0,curmin[j=0]=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||curmin[i]<curmin[k]))
				k=i;
		for (v[k]=1,sum+=curmin[k],i=0;i<n;i++)
			if (!v[i]&&mat[k][i]<curmin[i])
				curmin[i]=mat[pre[i]=k][i];		
		
		for(i=0;i<n;i++)
			if(v[i] && i!=k)
			dis[k][i] = dis[i][k] = max(dis[i][pre[k]],mat[k][pre[k]]);
	}

	for(ret = inf,i=0;i<n;i++)
	for(j=i+1;j<n;j++)
        if(mat[i][j]!=inf && pre[i]!=j && pre[j]!=i)
			found = true,ret = min(ret,sum+mat[i][j]-dis[i][j]);

	if(!found)ret = -1;

	return ret;
}

int mat[MAXN][MAXN];
int pre[MAXN];

int main()
{
	int m,n,i,j,u,v,w;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
         for(i=0;i<n;i++)
			 for(j=0;j<n;j++)
				 mat[i][j] = inf;
         for(i=0;i<m;i++)
		 {
			 scanf("%d%d%d",&u,&v,&w);
			 mat[u-1][v-1] = mat[v-1][u-1] = w;
		 }
         u = prim2nd(n,mat,pre,w);
		 printf("Cost: %d\n",w);
		 printf("Cost: %d\n",u);
	}
	return 0;
}
