#include<iostream>
using namespace std;
char Graph[501][501];
int data[101][101];
void Draw(int x,int y)
{Graph[x][y]='+';Graph[x][y+1]='-'; Graph[x][y+2]='-';Graph[x][y+3]='-';Graph[x][y+4]='+';
x--;
Graph[x][y]='|';Graph[x][y+1]=' '; Graph[x][y+2]=' ';Graph[x][y+3]=' ';Graph[x][y+4]='|';
Graph[x][y+5]='/';
x--;
Graph[x][y]='|';Graph[x][y+1]=' '; Graph[x][y+2]=' ';Graph[x][y+3]=' ';Graph[x][y+4]='|';
Graph[x][y+5]=' ';Graph[x][y+6]='+';
x--;
Graph[x][y]='+';Graph[x][y+1]='-'; Graph[x][y+2]='-';Graph[x][y+3]='-';Graph[x][y+4]='+';
Graph[x][y+5]=' ';Graph[x][y+6]='|';
x--;y++;
Graph[x][y]='/';Graph[x][y+1]=' '; Graph[x][y+2]=' ';Graph[x][y+3]=' ';Graph[x][y+4]='/';
Graph[x][y+5]='|';
x--;y++;
Graph[x][y]='+';Graph[x][y+1]='-'; Graph[x][y+2]='-';Graph[x][y+3]='-';Graph[x][y+4]='+';
}
int main(){
    int m,n;
    int i,j,k;
    int p,q;
    int maxx,maxy,t;
    cin>>m>>n;
    maxx=0;
    maxy=n*4+1+m*2;
    for(i=1;i<=m;i++)
      {t=0;
      for(j=1;j<=n;j++)
        {cin>>data[i][j];
        if(data[i][j]>t)t=data[i][j];
        }
      t=t*3+3+(m-i)*2;
      if(t>maxx)maxx=t;
      }
    for(i=1;i<=500;i++)
      for(j=1;j<=500;j++)
        Graph[i][j]='.';
    for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
      {p=maxx-(m-i)*2;
      q=(m-i)*2+(j-1)*4+1;
      for(k=1;k<=data[i][j];k++)
        Draw(p-(k-1)*3,q);
      }
    for(i=1;i<=maxx;i++)
      {for(j=1;j<=maxy;j++)
        cout<<Graph[i][j];
      cout<<endl;
      }
    return 0;
}
