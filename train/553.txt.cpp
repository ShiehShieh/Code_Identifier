#include <iostream>
using namespace std;
int main()
{
  long long o,n,m,map[2][31][31][31],now=0,s[2],dx,dy,dz;
  cin>>o>>n>>m;
  memset(map,0,sizeof(map));map[0][1][1][m]=1;s[0]=1;s[1]=n;
  for (int i=1;i<=o;i++)
  {
    now=1-now;memset(map[now],0,sizeof(map[now]));
    for (int j=2;j<n;j++) for (int x=0;x<=1;x++) for (int y=0;y<=1;y++)
        {
          map[now][s[x]][s[y]][j+1]+=map[1-now][s[x]][s[y]][j];
          map[now][s[x]][s[y]][j-1]+=map[1-now][s[x]][s[y]][j];
          map[now][s[x]][j+1][s[y]]+=map[1-now][s[x]][j][s[y]];
          map[now][s[x]][j-1][s[y]]+=map[1-now][s[x]][j][s[y]];
          map[now][j+1][s[x]][s[y]]+=map[1-now][j][s[x]][s[y]];
          map[now][j-1][s[x]][s[y]]+=map[1-now][j][s[x]][s[y]];
        }
    for (int x=0;x<=1;x++) for (int y=0;y<=1;y++) for (int z=0;z<=1;z++)
        {
          dx=(x==0)?2:n-1;dy=(y==0)?2:n-1;dz=(z==0)?2:n-1;
          map[now][dx][s[y]][s[z]]+=map[1-now][s[x]][s[y]][s[z]];
          map[now][s[x]][dy][s[z]]+=map[1-now][s[x]][s[y]][s[z]];
          map[now][s[x]][s[y]][dz]+=map[1-now][s[x]][s[y]][s[z]];
        }
  }
  cout<<map[now][1][1][m]<<endl;
  return 0;
}

