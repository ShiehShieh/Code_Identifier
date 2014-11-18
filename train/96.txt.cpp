#include<iostream>
using namespace std;
long i,j,k,l,n,m,min1,kk,ans[200],a[110][510];
__int64 map[110][510],f[110][510];
int main()
{
    
	 scanf("%ld%ld",&n,&m);
	 for (i=1;i<=n;i++)
		 for (j=1;j<=m;j++)
			 scanf("%I64d",&map[i][j]);
		 memset(ans,0,sizeof(ans));
         	 memset(a,0,sizeof(a));
		 for (j=1;j<=m;j++)
		 {
			 f[1][j]=map[1][j];
		 }

	 for(i=2;i<=n;i++)
	 {
		 for (j=1;j<=m;j++)
		 { f[i][j]=f[i-1][j]+map[i][j]; a[i][j]=2;}

		 for (j=2;j<=m;j++)
		 {	 if (f[i][j]>f[i][j-1]+map[i][j]) { f[i][j]=f[i][j-1]+map[i][j]; a[i][j]=1;}}

	     for (j=m-1;j>0;j--)
		 {	 if (f[i][j]>f[i][j+1]+map[i][j]) {f[i][j]=f[i][j+1]+map[i][j];a[i][j]=-1;}}
			 
	 }

	 min1=f[n][1]; kk=1;

      for (j=2;j<=m;j++)
		  if (min1>f[n][j]) {min1=f[n][j];kk=j;}
		 	 
 // printf("%ld  ",min1);
          i=n;  j=kk;  kk=1;  ans[kk]=j;
  
		  min1=min1-map[i][j];

		  while (min1!=0)
		  {
               if (a[i][j]==2) i--;
			   else if (a[i][j]==-1) j++;
				  else if (a[i][j]==1) j--;
			  kk++;
			 min1=min1-map[i][j];
			 ans[kk]=j;
			
		  }

		  for (i=kk;i>0;i--)
			  printf("%ld\n",ans[i]);

	return 0;
}

/*
0  0  0  0
-1  -1  2  1
2  2  2  2
*/
