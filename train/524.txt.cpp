#include<iostream>
using namespace std;
char a[1001][1001];
int b[1001][1001];
int flood(int x,int y,int r,int c)
{
    if (b[x][y]!=1)
    {
    a[x][y]='.';
    b[x][y]=1;
    if(x>1 && a[x-1][y]!='.') flood(x-1,y,r,c);
    if(x<r && a[x+1][y]!='.') flood(x+1,y,r,c);
    if(y>1 && a[x][y-1]!='.') flood(x,y-1,r,c);
    if(y<c && a[x][y+1]!='.') flood(x,y+1,r,c);
}
}
bool map(int r,int c)
{
    int flag=1;
    for(int x=1;x<=r-1;x++)
       for(int y=1;y<=c-1;y++)
    if((b[x][y]==1 && b[x][y+1]==1 && b[x+1][y+1]==1 && b[x+1][y]==0)
       || (b[x][y]==1 && b[x][y+1]==1 && b[x+1][y+1]==0 && b[x+1][y]==1)
        || (b[x][y]==1 && b[x][y+1]==0 && b[x+1][y+1]==1 && b[x+1][y]==1)
        || (b[x][y]==0 && b[x][y+1]==1 && b[x+1][y+1]==1 && b[x+1][y]==1))
    flag=0;
    if(flag==1)
    return 1;
    else return 0;
}
int main()
{
    int r,c,s=0,flag=1;
    char x;
    cin>>r>>c;
    for(int i=1;i<=r;i++)
       for(int j=1;j<=c;j++)
    b[i][j]=0;
    
    for(int i=1;i<=r;i++)
       for(int j=1;j<=c;j++)
       {cin>>x;a[i][j]=x;}
    
    {
    for(int i=1;i<=r;i++)
       for(int j=1;j<=c;j++)
       {
               if(a[i][j]=='#')
               {
                    flood(i,j,r,c);
                    if(map(r,c)==0)
                    {flag=0;break;}
                    s++;
               }
       }
    }
    if(flag==0)
    cout<<"Bad placement."<<endl;
    else cout<<"There are "<<s<<" ships."<<endl;
    
}

