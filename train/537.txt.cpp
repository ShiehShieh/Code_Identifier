#include<iostream>
using namespace std;
int i,j,m,n,l,a[250][250],b[250][250];
int main()
{
	cin>>m>>n;
	for(i=1;i<=m;i++) for(j=1;j<=n;j++) cin>>a[i][j];
	for(i=1;i<=n;i++) b[1][i]=a[1][i];
	for(i=2;i<=m;i++) 
	{
		for(j=1;j<=n;j++) 
		{
			if(j==1) b[i][j]=a[i][j]+max(b[i-1][j],b[i-1][j+1]);
			else
			{
				if(j==n) b[i][j]=a[i][j]+max(b[i-1][j],b[i-1][j-1]);
				else
				{
					b[i][j]=a[i][j]+max(max(b[i-1][j-1],b[i-1][j]),b[i-1][j+1]);
				}
			}
		}
	}
	l=n/2;
	cout<<max(max(b[m][l],b[m][l+1]),b[m][l+2])<<endl;
	cin>>i;
	return 0;
}
