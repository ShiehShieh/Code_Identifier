#include <stdio.h>
#include <stdlib.h>

typedef struct
{
        int x;
        int y;
}coordinate;
coordinate start;
coordinate end;
int t,r,l;
char map[30][30];
static int state[30][30];  
int doit(int xx,int yy,int value)
{
    state[xx][yy]=value;
    int temp;
    if(map[xx-1][yy]!='o')
    {
      if(map[xx-1][yy]=='#') temp=2;
      else temp=1;
      if((value+temp)<state[xx-1][yy])
      {
             doit(xx-1,yy,value+temp);
      }
    }
    if(map[xx][yy-1]!='o')
    {
      if(map[xx][yy-1]=='.') temp=1;
      else temp=2;
      if((value+temp)<state[xx][yy-1])
      {
             doit(xx,yy-1,value+temp);
      }
    }
    if(map[xx+1][yy]!='o')
    {
      if(map[xx+1][yy]=='.') temp=1;
      else temp=2;
      if((value+temp)<state[xx+1][yy])
      {
             doit(xx+1,yy,value+temp);
      }
    }
    if(map[xx][yy+1]!='o')
    {
      if(map[xx][yy+1]=='.') temp=1;
      else temp=2;
      if((value+temp)<state[xx][yy+1])
      {
             doit(xx,yy+1,value+temp);
      }
    }
    
    
}
int main()
{
    int i,j;
    scanf("%d%d%d",&t,&r,&l);
    for(i=1;i<=l;i++)
    {
                     scanf("%s",map[i]+1);
    }
    for(i=1;i<=l;i++)
    {
                     for(j=1;j<=r;j++)
                     {
                                      if(map[i][j]=='s')
                                      {
                                                        start.x=i;
                                                        start.y=j;
                                                        map[i][j]='.';
                                      }
                                      else if(map[i][j]=='m')
                                      {
                                           end.x=i;
                                           end.y=j;
                                           map[i][j]='.';
                                      }
                     }
    }
    for(i=0;i<=l+1;i++)
    {
                       for(j=0;j<=r+1;j++)
                       {
                                          state[i][j]=2000;
                       }
    }
    for(i=0;i<=l+1;i++)
    {
                     state[i][0]=0;
                     state[i][r+1]=0;
    }
    for(i=0;i<=r+1;i++)
    {
                     state[0][i]=0;
                     state[l+1][i]=0;
    }
    doit(start.x,start.y,0);
    if(state[end.x][end.y]>=t) printf("55555\n");
    else printf("%d\n",state[end.x][end.y]);
    
}

