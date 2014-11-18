#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
        int n,m,t,y;
	cin>>n>>m>>t>>y;
	n+=2;
	m+=2;
	t+=2;
	y+=2;
	int f[19][19]={0};
	f[2][2]=1;
	f[t][y]=-1;
	f[t-2][y-1]=-1;
	f[t-2][y+1]=-1;
	f[t-1][y-2]=-1;
	f[t-1][y+2]=-1;
	f[t+1][y-2]=-1;
	f[t+1][y+2]=-1;
	f[t+2][y-1]=-1;
	f[t+2][y+1]=-1;
	for (int i=2;i<=n;i++)
	for (int j=2;j<=m;j++){
	if(i!=2||j!=2)
		if(f[i][j]==-1) 
			f[i][j]=0;
		else
			f[i][j]=f[i-1][j]+f[i][j-1];
	}
	cout<<f[n][m]<<endl;
	return 0;
}


