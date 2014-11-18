#include <iostream>
#include <cstring>
using namespace std;
const int dxx[8]={1,1,1,0,0,-1,-1,-1};
const int dyy[8]={-1,0,1,-1,1,-1,0,1};
int x1,y1,x2,y2,n,m;
bool m1[800][800],m2[800][800];
char a[800][800];
bool check(int x,int y,int dir)
{
	while(x<=n&&y<=m&&x>=1&&y>=1){
		x=x+dxx[dir],y=y+dyy[dir];
		if(!m2[x][y]) return false;
		else if(x==x1&&y==y1) return true;
	}
}
void bfs()
{
	const int dx[4]={0,0,1,-1};
	const int dy[4]={-1,1,0,0};
	int ans[20000][4];
	memset(ans,0,sizeof(ans));
	if(!m2[x2][y2]||!m2[x1][y1]){
		cout<<"Impossible!"<<endl;
		return;
	}
	for(int i=0;i<8;i++){
		if(check(x2,y2,i)){
			cout<<0<<endl;
			return;
		}
	}
	int f=0,r=1;
	ans[r][1]=x2;ans[r][2]=y2;ans[r][3]=0;
	m2[x2][y2]=false;
	r++;
	int x,y,z;
	while(f<=r){
		f++;
		x=ans[f][1];y=ans[f][2];z=ans[f][3];
		for(int i=0;i<4;i++){
			if(x+dx[i]<=n&&x+dx[i]>=1&&y+dy[i]<=m&&y+dy[i]>=1&&m2[x+dx[i]][y+dy[i]]){
				ans[r][1]=x+dx[i];ans[r][2]=y+dy[i];ans[r][3]=z+1;
				m2[ans[r][1]][ans[r][2]]=false;
				for(int j=0;j<8;j++){
					if(check(ans[r][1],ans[r][2],j)){
						cout<<ans[r][3]<<endl;
						return;
					}
				}
				r++;
			}
		}
	}
	cout<<"Impossible!"<<endl;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='O') m1[i][j]=true;
			else m1[i][j]=false;
		}
	while(cin>>x1>>y1>>x2>>y2&&x1&&y1&&x2&&y2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				m2[i][j]=m1[i][j];
			bfs();
	}
	return 0;
}
