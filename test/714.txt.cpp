#include<iostream>
using namespace std;
int a[2000],b[2000],f[2000][2000];
int main()
{
    int n,i,j,x1,y1,x,y;
    cin>>n;
    for (i=1;i<=n;i++)
    a[i]=i;
    for (i=1;i<=n;i++)
    {
        while (1)
        {
              cin>>j;
              if(j==0)break;
              f[i][j]=1;
              x=i;
              y=j;
              x1=a[x];
              y1=a[y];
              for (j=1;j<=n;j++)
              {
                  if(a[j]==y1)a[j]=x1;
              }
        }
    }
    for (i=1;i<=n;i++)
    {
        b[a[i]]=1;
    }
    int s=0;
    for (i=1;i<=n;i++)
    {
        s+=b[i];
    }
    cout<<s;
}

