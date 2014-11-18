#include <iostream>
using namespace std;
bool map[100][100];
int n,m;
void christ(int x,int y)
{map[x][y]=0;
if(x>0&&map[x-1][y]) christ(x-1,y);
if(x<n-1&&map[x+1][y]) christ(x+1,y);
if(y>0&&map[x][y-1]) christ(x,y-1);
if(y<m-1&&map[x][y+1]) christ(x,y+1);
if(x>1&&map[x-2][y]) christ(x-2,y);
if(x<n-2&&map[x+2][y]) christ(x+2,y);
if(y>1&&map[x][y-2]) christ(x,y-2);
if(y<m-2&&map[x][y+2]) christ(x,y+2);
if(x>0&&y>0&&map[x-1][y-1]) christ(x-1,y-1);
if(x>0&&y<m-1&&map[x-1][y+1]) christ(x-1,y+1);
if(x<n-1&&y>0&&map[x+1][y-1]) christ(x+1,y-1);
if(x<n-1&&y<m-1&&map[x+1][y+1]) christ(x+1,y+1);
}
int main()
{int i,j,s=0;
char c;
cin>>n>>m;
for (i=0;i<n;i++)
for (j=0;j<m;j++)
{cin>>c;if(c=='-') map[i][j]=0;else map[i][j]=1;}
for (i=0;i<n;i++)
for (j=0;j<m;j++)
if(map[i][j]) {s++;christ(i,j);}
cout<<s;
return 0;
}
 


