#include <iostream.h>
#include<iomanip.h>
#include<string.h>
int min(int w,int c)
{int temp;
 if (w<c) temp=w;
 else
 temp=c;
 return temp;
}
int max(int w,int c)
{
 int temp;
 if (w>c) temp=w;
 else
 temp=c;
 return temp;
}
void knapsack(int v[],int w[],int c,int n,int**m)
{
  int jmax=min(w[n]-1,c);
  for(int j=0;j<=jmax;j++)
    m[n][j]=0;
  for(int jj=w[n];jj<=c;jj++)
    m[n][jj]=v[n];
  for(int i=n-1;i>1;i--){                         
    jmax=min(w[i]-1,c);
    for(int j=0;j<=jmax;j++)
      m[i][j]=m[i+1][j];
    for(int jj=w[i];jj<=c;jj++)
      m[i][jj]=max(m[i+1][jj],m[i+1][jj-w[i]]+v[i]);
      }
  m[1][c]=m[2][c];
  if(c>=w[1])
     m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
 cout<<m[1][c];
}

int main()
{
 int n,c;
 int **m;
 cin>>n>>c;
   int *v=new int[n+1];
   int *w=new int[n+1];
 for(int i=1;i<=n;i++)
  {
         cin>>v[i];

  cin>>w[i];
  }
 int *x=new int[n+1];
 m=new int*[n+1];
 for(int p=0;p<n+1;p++)
 {
  m[p]=new int[c+1];
}
 knapsack(v,w,c,n,m);
 return 0;
}


