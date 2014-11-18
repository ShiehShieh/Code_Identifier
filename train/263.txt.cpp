#include<iostream>
using namespace std;
long long map[1005][1005]={0};
long long n,m,x1,y1,x2,y2,i,j,k;
int main()
{   cin>>m>>n>>y1>>x1>>y2>>x2;
    map[x1][y1]=1;
    for(j=y1;j<=y2;j++)
       for(i=1;i<=n;i++)
          {if(i+1<=n&&j+2<=n){map[i+1][j+2]+=map[i][j];}
           if(i+2<=n&&j+1<=n){map[i+2][j+1]+=map[i][j];}
           if(i-1>=1&&j+2<=n){map[i-1][j+2]+=map[i][j];}
           if(i-2>=1&&j+1<=n){map[i-2][j+1]+=map[i][j];}
          }
    if(map[x2][y2]!=0)cout<<map[x2][y2]<<"00000000"<<endl;
    else              cout<<"NO"<<endl;
    return 0;
}
