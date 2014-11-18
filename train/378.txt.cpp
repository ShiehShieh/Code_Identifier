#include<iostream>
using namespace std;

char a[100][100];
const int xx[]={-1,-1,-1,0,1,1,1,0,-2,0,2,0},
          yy[]={-1,0,1,1,1,0,-1,-1,0,-2,0,2};

void change(int y=0,int x=0)
{
     a[y][x]='-';
     for(int i=0;i<12;i++)
     {
         if ( a[y+yy[i]][x+xx[i]] =='#' && y+yy[i]>=0 && y+yy[i]<100
             && x+xx[i]>=0 && x+xx[i]<100)
             change(y+yy[i],x+xx[i]);
     }
}

int main()
{
    int n,m,i,j,s=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) cin>>a[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if ( a[i][j]=='#')
            {
                 s++;
                 change(i,j);
            }
        }
    cout<<s<<endl;
    return 0;
}
