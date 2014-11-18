//Floodfill算法
#include<iostream>
using namespace std;
int X[]={-1,-1,-1,0,1,1,1,0,0,2,0,-2,};
int Y[]={-1,0,1,1,1,0,-1,-1,2,0,-2,0};
char a[100][100];

int flood(int x1,int y1)
{
    a[x1][y1]='-';
    for(int i=0;i<12;i++)
    {
       if(a[x1+X[i]][y1+Y[i]]=='#' && x1+X[i]>=0 && x1+X[i]<100 && y1+Y[i]>=0 && y1+Y[i]<100)
       flood(x1+X[i],y1+Y[i]);
    }
    
}
int main()
{
    int s=0,n,m;
    cin>>n>>m;
    char t;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
          cin>>t;
          a[i][j]=t;
      }
     for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        {
              if(a[i][j]=='#')
              {
               s++;
              flood(i,j);
              }
        }
      cout<<s<<endl;
} 
