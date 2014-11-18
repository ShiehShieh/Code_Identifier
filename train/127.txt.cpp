#include<iostream>
using namespace std;
long f[110][60][60],a[100][100];
long i,j,k,l,n,m,i1,i2;
long max(long x,long y)
{
	if(x>y) return x; else return y;
}
int main()
{

	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));

	scanf("%ld%ld",&n,&m);

	for (i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%ld",&a[i][j]);

		
	//	printf("%d  %d",n ,m);
     
		for (k=2;k<=(n+m-1);k++)
			for (i1=1;i1<=n;i1++)
					for ( i2=1;i2<=n;i2++)
						if (k-i2>0 && k-i1>0 && i1!=i2)
					{
							//(上上)(上左)(左上)(左左)
							f[k][i1][i2]=max(f[k-1][i1][i2],f[k-1][i1][i2-1]);
							f[k][i1][i2]=max(f[k][i1][i2],f[k-1][i1-1][i2]);
                            f[k][i1][i2]=max(f[k][i1][i2],f[k-1][i1-1][i2-1]);
							f[k][i1][i2]=f[k][i1][i2]+a[i1][k-i1]+a[i2][k-i2];

						

					}
					/*	k=n+m;
						f[n+m][n][m]=f[k-1][n-1][n]+a[n][m];*/
						printf("%ld\n",f[n+m-1][n-1][n]);	
	return 0;
}
