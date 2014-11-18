#include<iostream>
using namespace std;
int main()
{
    int m,n,k,maxi,maxj,max,i,j,a,b;
    int sum=0;
    bool f=true; 
    cin>>m>>n>>k;
    k--;
    int map[m][n];
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        cin>>map[i][j];
    max=0;
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        if(map[i][j]>max)
        {
             max=map[i][j];
             maxi=i;
             maxj=j;     
        }
    if(k-(maxi+1)-(maxi+1)<0)
    {
         cout<<sum<<endl;
         return 0;
    }
    else
    {
         sum+=map[maxi][maxj];
         a=maxi;b=maxj;
         k-=maxi+1;
         map[a][b]=0;
    }
    while(f)
    {
         max=0;
         for(i=0;i<m;i++)
           for(j=0;j<n;j++)
             if(map[i][j]>max)
             {
                  max=map[i][j];
                  maxi=i;
                  maxj=j;        
             }
         if(max==0)
           break;
         if(k-(abs(maxi-a)+abs(maxj-b)+1)-(maxi+1)<0)
           break;
         else
         {
              sum+=map[maxi][maxj];
              k-=abs(maxi-a)+abs(maxj-b)+1;
              a=maxi;b=maxj;
              map[a][b]=0;
         }
    }
    cout<<sum<<endl;
    return 0;
}
