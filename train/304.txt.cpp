#include<iostream>
using namespace std;
long long map[16][16];
int main()
{int n,m,a,b,i,j;
 cin>>n>>m;
 cin>>a>>b;
 for(i=0;i<=n;i++)
   for(j=0;j<=m;j++)
      map[i][j]=-1;
 map[a][b]=0;
 if(a-1>=0)
   {if(b-2>=0)
      map[a-1][b-2]=0;
    if(b+2<=m)
      map[a-1][b+2]=0;
   }
 if(a-2>=0)
   {if(b-1>=0)
      map[a-2][b-1]=0;
    if(b+1<=m)
      map[a-2][b+1]=0;
   }
 if(a+1<=n)
   {if(b-2>=0)
      map[a+1][b-2]=0;
    if(b+2<=m)
      map[a+1][b+2]=0;
   }
 if(a+2<=n)
   {if(b-1>=0)
      map[a+2][b-1]=0;
    if(b+1<=m)
      map[a+2][b+1]=0;
   }
 map[0][0]=1;
 for(i=1;i<=m;i++)
   if(map[0][i]==-1)
     map[0][i]=map[0][i-1];
 for(i=0;i<=n;i++)
   if(map[i][0]==-1)
     map[i][0]=map[i-1][0];
  
 for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
     if(map[i][j]==-1)
       map[i][j]=map[i-1][j]+map[i][j-1];
 cout<<map[n][m]<<endl;
 return 0;
}       

