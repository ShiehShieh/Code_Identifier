//15:46-
#include <iostream>
#include <math.h>
#define maxn 300
typedef struct Direct{
    int x,y;
}Direct;
Direct dir[5]={{0,0},{-1,-1},{-1,1},{1,-1},{1,1}};
Direct queue[maxn*maxn];

bool face[2][maxn][maxn][5];
bool visited[maxn][maxn];

void Floodfill(int i,int j,int &tot,bool &found)
{
    int top=-1,tail=0,x,y,collect,k;
    tot=0;
    found=false;
    visited[i][j]=true;
    queue[tail].x=i;queue[tail].y=j;
    while(top<tail)
    {
        top++;
        x=queue[top].x;y=queue[top].y;
        collect=0;
        for (k=1;k<=4;k++)
        {
            if (face[0][x][y][k]||face[1][x][y][k])
            {
                if (face[0][x][y][k]) {found=true;collect++;}
                if (face[1][x][y][k]) {found=true;collect--;}
                if (!visited[x+dir[k].x][y+dir[k].y])
                {
                    visited[x+dir[k].x][y+dir[k].y]=true;
                    tail++;
                    queue[tail].x=x+dir[k].x;queue[tail].y=y+dir[k].y;
                }
            }
        }
        tot+=abs(collect);
    }
}

void Solve(int n,int m)
{
    int i,j,tot,ans=0;
    bool found;
    for (i=0;i<=n;i++)
        for (j=0;j<=m;j++)
            if (!visited[i][j])
            {
                Floodfill(i,j,tot,found);
                if (found&&tot==0) ans++;else ans+=tot/2;
            }
    printf("%d\n",ans);
}

int main()
{
    int n,m,k,i,j;
    char s[maxn];
    memset(face,0,sizeof(face));
    memset(visited,0,sizeof(visited));
    scanf("%d%d",&n,&m);
    for (k=0;k<2;k++)
        for (i=0;i<n;i++)
        {
            scanf("%s",&s);
            for (j=0;j<m;j++)
            {
                switch(s[j])
                {
                    case '\\':
                     face[k][i][j][4]=true;
                     face[k][i+1][j+1][1]=true;
                     break;
                    case '/':
                        face[k][i][j+1][3]=true;
                        face[k][i+1][j][2]=true;
                        break;
                    case 'X':
                        face[k][i][j][4]=true;
                        face[k][i+1][j+1][1]=true;
                        face[k][i][j+1][3]=true;
                        face[k][i+1][j][2]=true;
                        break;
                }
            }
        }

    Solve(n,m);
    //getchar();getchar();
    return 0;
}
