#include<cstdio>
using namespace std;

int min(int a,int b,int c){
    int Imin=10000;
    if (Imin>a)
       Imin=a;
    if (Imin>b)
         Imin=b;
    if (Imin>c)
         Imin=c;
	return Imin;
}
int map[1000][1000];
int main()
{
    //freopen("build.in","r",stdin);
    //freopen("build.out","w",stdout);
    int n,m,max=0;
    int i,j;
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            scanf("%d",&map[i][j]);
    for (i=1;i<n;i++)
        for (j=1;j<m;j++)
            if (map[i][j])
               map[i][j]=min(map[i-1][j],map[i][j-1],map[i-1][j-1])+1;
    for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			if (max<map[i][j])
				max=map[i][j];
    
	printf("%d",max);
    //while (1);
    return 0;    
}
