#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int step[8][2]={{1,-2},{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};

int map[20][20];
bool can[20][20];
int n,m,x,y;

int main()
{
    int i,j;
    scanf("%d %d %d %d",&n,&m,&x,&y);
    memset(map,0,sizeof(map));
    memset(can,-1,sizeof(can));
    can[x][y]=false;
    for(i=0;i<8;i++)
    {
        int tx=x+step[i][0];
        int ty=y+step[i][1];
        if(tx>=0&&tx<=n&&ty>=0&&ty<=m)   can[tx][ty]=false;
    }
    if(!can[0,0]&&!can[n,m])  printf("0\n");
    else
    {
        map[0][0]=1;
        can[0][0]=false;
        for(i=0;i<=n;i++)
           for(j=0;j<=m;j++)
              if(can[i][j])  map[i][j]=map[i-1][j]+map[i][j-1];
        printf("%d\n",map[n][m]);
    }
    return 0;
}
    

