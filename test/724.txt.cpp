#include<cstdio>
#include<queue>
#include<fstream>
using namespace std;
const int N = 101;
int mp[N][N];
int d[12][2]={{-1,-1},{0,-1},{1,-1},{1,0},{2,0},{0,-2},
                {1,1},{0,1},{-1,1},{-1,0},{-2,0},{0,2}};
struct Position{
    int i,j;
    Position(int x,int y) { i=x;j=y; }
};
inline bool ok(int x,int y,int n,int m)
{
    return (x>0&&y>0&&x<=n&&y<=m);
}
void floodfill(int x,int y,int n,int m,int res)
{
    mp[x][y] = res;
    for(int k=0;k<12;++k)
    {
        int sx(d[k][0]+x),
            sy(d[k][1]+y);
        if(ok(sx,sy,n,m)&&!mp[sx][sy]) floodfill(sx,sy,n,m,res);
    }
}
const char path1[]="E:\\MyCode\\test\\lzs.txt";
int main()
{
   int n,m;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
       for(int i=1;i<=n;++i)
           for(int j=1;j<=m;++j)
           {
                  char ch;
                  scanf(" %c",&ch);
                  if(ch=='-') mp[i][j] = -1;
                  else mp[i][j] = 0;
           }
        int res(0);
        for(int i=1;i<=n;++i)
           for(int j=1;j<=m;++j)
             if( !mp[i][j] )
                   floodfill(i,j,n,m,++res);
        printf("%d\n",res);
   }
   return 0;
}
