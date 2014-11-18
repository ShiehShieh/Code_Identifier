#include <stdio.h>
#include <iostream>
using namespace std;

const int size=105;

char map[size][size];
int r,c,x1,y1,x2,y2;
int step[12][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{1,-1},{-1,1},{1,1},{2,0},{-2,0},{0,2},{0,-2}};

void floodfill(int i,int j)
{
    map[i][j]='-';
    for(int m=0;m<12;m++)
    {
        int ti=i+step[m][0];
        int tj=j+step[m][1];
        if(ti>=0&&ti<r&&tj>=0&&tj<c&&map[ti][tj]=='#')
           floodfill(ti,tj);
    }
}

int main()
{
    scanf("%d %d",&r,&c);
    getchar();
    for(int i=0;i<r;i++)
       scanf("%s",map[i]);
    int ships=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(map[i][j]=='#')
            {
                ships++;
                floodfill(i,j);
            }
        }
    }
    printf("%d\n",ships);
    return 0;
}
                
