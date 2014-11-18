#include<stdio.h>

typedef struct {
  int lx,ly;
} node;

int n,m,i,j,w,ans;
node q[50000];
int head,tail;
bool f[201][201][5],b[201][201][5];
bool visited[201][201];
int ha[5]={0,-1,-1,1,1};
int hb[5]={0,-1,1,-1,1};
bool found;
char t;

int abs(int a)
{
  if ( a<0 ) return -a; else return a;
}

void floodfill(int x,int y)
{
  int k,InNum,OutNum;
  head=0; tail=1;
  q[1].lx=x; q[1].ly=y;
  visited[x][y]=true;
  while ( head<tail )  
  {
    head++;
    x=q[head].lx; y=q[head].ly;
    InNum=0; OutNum=0;
    for ( k=1;k<=4;k++ )
      {
        if ( f[x][y][k] || b[x][y][k] ) 
	  {
            if ( f[x][y][k] ) InNum++;
            if ( b[x][y][k] ) OutNum++;
            if ( !visited[x+ha[k]][y+hb[k]] ) 
              {
                visited[x+ha[k]][y+hb[k]]=true;
                tail++;
                q[tail].lx=x+ha[k]; q[tail].ly=y+hb[k];
              }
      }
    }
    if ( InNum!=0 || OutNum!=0 ) found=true;
    w+=abs(InNum-OutNum);
  }
}

int main()
{
  scanf("%d%d",&n,&m);
  getchar();
  for (i=1;i<=n;i++)
   {
     for (j=1;j<=m;j++)
	 {
	    scanf("%c",&t);
        switch (t) {
		case '\\' : 
		  f[i][j][1]=true; 
		  f[i-1][j-1][4]=true; 
		  break;
        case '/' : 
		  f[i][j-1][2]=true;
		  f[i-1][j][3]=true;
          break;        
        case 'X' :
		  f[i][j][1]=true; 
		  f[i-1][j-1][4]=true;
          f[i][j-1][2]=true; 
		  f[i-1][j][3]=true;
		  break;
		}
	 }
     getchar();
   }
  
  for (i=1;i<=n;i++)
   {
     for (j=1;j<=m;j++)
	 {
		scanf("%c",&t);
        switch (t) {
        case '\\':
	      b[i][j][1]=true; 
		  b[i-1][j-1][4]=true;
          break;
        case '/':
		  b[i][j-1][2]=true; 
		  b[i-1][j][3]=true;
          break;        
        case 'X':
		  b[i][j][1]=true; 
		  b[i-1][j-1][4]=true;
          b[i][j-1][2]=true; 
		  b[i-1][j][3]=true;
		  break;
		}
	 }
     getchar();
   }
   for ( i=0;i<=n;i++ )
    for ( j=0;j<=m;j++ )
     if ( !visited[i][j] ) 
	 {
       w=0; found=false;
       floodfill(i,j);
       if (found && w==0) ans++;
          else ans+=w/2; 
     }   
   printf("%d\n",ans); 
   return 0;
}
