#include<iostream>
using namespace std;
int map[16][16]={-1};
main(){
       int n,m,x,y;
       cin>>n>>m>>x>>y;
       
       int i,j;
       for (i=0;i<=n;i++)
       for (j=0;j<=m;j++)
       {
           map[i][j]=-1;
       }
       map[x][y]=0;
       map[x+2][y-1]=0;
       map[x+2][y+1]=0;
       map[x-2][y-1]=0;
       map[x-2][y+1]=0;
       map[x+1][y+2]=0;
       map[x+1][y-2]=0;
       map[x-1][y+2]=0;
       map[x-1][y-2]=0;
       map[0][0]=1;
       for (i=0;i<=n;i++)
       for (j=0;j<=m;j++)
       {
           if (map[i][j])
           {
                         if (i>0){
                         if (map[i][j]<0)map[i][j]=0;
                                  map[i][j]+=map[i-1][j];
                                  }
                         if (j>0){
                         if (map[i][j]<0)map[i][j]=0;
                                  map[i][j]+=map[i][j-1];
                                  }
           }
       }
       cout<<map[n][m];
       }

