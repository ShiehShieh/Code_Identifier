#include <stdio.h>
#include <stdlib.h>
int bx,by,hx,hy,flag[16][16]={0};
long count=0;
void getin()
{
scanf("%d%d%d%d",&bx,&by,&hx,&hy);
flag[hx+1][hy-2]=1;
flag[hx+2][hy-1]=1;
flag[hx+2][hy+1]=1;
flag[hx+1][hy+2]=1;
flag[hx-1][hy+2]=1;
flag[hx-2][hy+1]=1;
flag[hx-2][hy-1]=1;
flag[hx-1][hy-2]=1;
flag[hx][hy]=1;
}

void path(int x,int y)
{
if(flag[x][y]!=1&&x<=bx&&y<=by)
{
if(x==bx&&y==by)count++;
else
{
path(x,y+1);
path(x+1,y);
}
}
}
int main()
{
 getin();
 path(0,1);
 path(1,0);
 printf("%ld",count);
 return 0;
}

