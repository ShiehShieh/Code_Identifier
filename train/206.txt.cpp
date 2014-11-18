#include<iostream>
using namespace std;
int m,n,i,j,k,l,a[50][50],aa[51][51][51][51];
int dp(int x1,int y1,int x2,int y2);
int sed(int x1,int y1,int x2,int y2,int xx1,int yy1,int xx2,int yy2)
{
    if (aa[x1][y1][x2][y2]==-1) aa[x1][y1][x2][y2]=dp(x1,y1,x2,y2);
    return aa[x1][y1][x2][y2];
}
int dp(int x1,int y1,int x2,int y2)
{
	if(!((x1==m) && (y1==n-1)) && !((x2==m-1) && (y2==n)))
	{
		if(x1==m)
		{
			if (y2==n) return a[x1][y1]+a[x2][y2]+sed(x1,y1+1,x2+1,y2,x1,y1,x2,y2);
			else
			{
				if(x2+1==x1) return a[x1][y1]+a[x2][y2]+sed(x1,y1+1,x2,y2+1,x1,y1,x2,y2);
                else return a[x1][y1]+a[x2][y2]+max(sed(x1,y1+1,x2+1,y2,x1,y1,x2,y2),sed(x1,y1+1,x2,y2+1,x1,y1,x2,y2));
			}
		}
		else
		{
			if(y2==n)
			{
				if(y1+1==y2) return a[x1][y1]+a[x2][y2]+sed(x1+1,y1,x2+1,y2,x1,y1,x2,y2);
				else return a[x1][y1]+a[x2][y2]+max(sed(x1+1,y1,x2+1,y2,x1,y1,x2,y2),sed(x1,y1+1,x2+1,y2,x1,y1,x2,y2));
			}
			else
			{
				if(x2+1==x1) return a[x1][y1]+a[x2][y2]+max(max(sed(x1+1,y1,x2+1,y2,x1,y1,x2,y2),sed(x1+1,y1,x2,y2+1,x1,y1,x2,y2)),sed(x1,y1+1,x2,y2+1,x1,y1,x2,y2));                                                        
				else return a[x1][y1]+a[x2][y2]+max(max(sed(x1+1,y1,x2+1,y2,x1,y1,x2,y2),sed(x1+1,y1,x2,y2+1,x1,y1,x2,y2)),max(sed(x1,y1+1,x2+1,y2,x1,y1,x2,y2),sed(x1,y1+1,x2,y2+1,x1,y1,x2,y2)));                           
			}
		}
	}
	else return a[x1][y1]+a[x2][y2];
}
int main()
{
	cin>>m>>n;
	for(i=1;i<=m;i++)for(j=1;j<=n;j++) cin>>a[i][j];
	for(i=1;i<=m;i++)for(j=1;j<=n;j++)for(k=1;k<=m;k++)for(l=1;l<=n;l++) aa[i][j][k][l]=-1;
	cout<<dp(2,1,1,2)<<endl;
}
