#include<iostream>
using namespace std;
int n,m,a[1000][1000];
long int b[1000][1000];
int maxn;
long int maxm(long int aa,long int cc)
{
     if(aa>cc)return aa;
     else return cc;
}
long int search(long int r,long int c)
{
    if(b[r][c]==0)
    {
      if(a[r+1][c]<a[r][c])b[r][c]=maxm(search(r+1,c),b[r][c]);
      if(a[r-1][c]<a[r][c])b[r][c]=maxm(search(r-1,c),b[r][c]);
      if(a[r][c+1]<a[r][c])b[r][c]=maxm(search(r,c+1),b[r][c]);
      if(a[r][c-1]<a[r][c])b[r][c]=maxm(search(r,c-1),b[r][c]);
      b[r][c]++;
    }
    return b[r][c];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>a[i][j];
    for(int i=1;i<=n;i++)a[i][0]=a[i][m+1]=20000;
    for(int i=1;i<=m;i++)a[0][i]=a[n+1][i]=20000;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      {
              b[i][j]=search(i,j);
              if(b[i][j]>maxn)maxn=b[i][j];
      }
   cout<<maxn; 
}

