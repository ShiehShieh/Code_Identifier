#include<iostream>
using namespace std;
int n,a,b,c,k,d,e,g,ans;
int f[40][21][21][21];
int v[40][40];
int pos[8][3]={0,0,0,-1,-1,-1,0,0,-1,0,-1,0,-1,0,0,-1,-1,0,-1,0,-1,0,-1,-1};
int vv(int aa,int bb,int cc,int dd,int ee,int ff)
{
    int tem=v[aa][bb];
    tem+=v[cc][dd];
    tem+=v[ee][ff];
    return tem;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        cin>>v[i][j];
    int all=v[1][1]+v[1][2]+v[1][3]+v[2][1]+v[2][2]+v[3][1];
    int end=v[n][n-1]+v[n-1][n]+v[n][n];
    f[3][1][2][3]=f[3][1][3][2]=f[3][2][1][3]=all;
    f[3][2][3][1]=f[3][3][1][2]=f[3][3][2][1]=all;
    for(k=4;k<=2*n-3;k++)
      for(a=1;a<=k;a++)
        for(b=1;b<=k;b++) 
          for(c=1;c<=k;c++)
          {
            d=k+1-a,e=k+1-b,g=k+1-c;
            if(a<=n&&b<=n&&c<=n&&d<=n&&e<=n&&g<=n)
            if(a!=b&&b!=c&&c!=a)
               for(int i=0;i<=7;i++)
               {
               int ax=a+pos[i][0],bx=b+pos[i][1],cx=c+pos[i][2];
               int ay=k-ax,by=k-bx,cy=k-cx;
               if(ax>=1&&ay>=1&&bx>=1&&by>=1&&cx>=1&&cy>=1)
               {
                 int value=f[k-1][ax][bx][cx]+v[a][d]+v[b][e]+v[c][g];    
                 if(value>f[k][a][b][c])
                 f[k][a][b][c]=value;
               }
              }
          }
   ans=f[2*n-3][n][n-1][n-2]+end;
   cout<<ans;
}

