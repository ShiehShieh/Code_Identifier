#include<iostream>
using namespace std;
const int N=20010;
const int M=35;
int a[M];
int f[M][N];

int main()
{
	int w,n,i,j,sum;
	scanf("%d%d",&w,&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0][0]=0;
	for(i=1;i<=w;i++) f[0][w]=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=w;j++) {
			f[i][j]=f[i-1][j];
			if(j>=a[i]) {
				if(f[i-1][j-a[i]]+a[i]>f[i][j]) f[i][j]=f[i-1][j-a[i]]+a[i];				
			}
		}
	}
	for(sum=0,i=1;i<=w;i++) if(f[n][i]>sum) sum=f[n][i];
	printf("%d\n",w-sum);
	return 0;
}
