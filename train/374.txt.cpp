
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int m,n,t;
    int pea=0;
    cin>>m>>n>>t;
    int a[m+1][n+1];
    int i,j,k;
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
          cin>>a[i][j];
    int x=0,y=0;
    
    int step;
    bool act=0;
    int max=-1,maxi=0,maxj=0;
    
    do{
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
          if(a[i][j]>max)
          {
             max=a[i][j];
             maxi=i;
             maxj=j;
          }
    if(y==0) y=maxj;//IMPORTANT
    step=fabs(x-maxi)+fabs(y-maxj)+1+maxi;
    
    if(step<=t)
    {
        act=1;
        pea+=max;
        t=t-(fabs(x-maxi)+fabs(y-maxj)+1);
        x=maxi;
        y=maxj;
        max=-1;
        a[maxi][maxj]=0;
    }
    else act=0;
    }while(act);
    
    cout<<pea;
    
    
    return 0;
}

