#include <iostream>
using namespace std;

int n;
int d[31],a[31][31];
int f[31][31];

void init()
{
     scanf("%d",&n);
     for (int i=1;i<=n;i++)
       scanf("%d",&d[i]);
}

int dfs(int l,int r)
{
    if (f[l][r]!=0)
      return f[l][r];
    if (l==r)
      {
             f[l][r]=d[l];
             a[l][r]=l;
             return f[l][r];
      }
    if (l > r)
      {
            f[l][r]=1;
            return 1;
      }
    for (int k=l;k<=r;k++)
      if(dfs(l,k-1)*dfs(k+1,r)+d[k] > f[l][r])
        {
           a[l][r]=k;
           f[l][r]=dfs(l,k-1)*dfs(k+1,r)+d[k];
        }
    
    return f[l][r];
}

int print(int l,int r)
{
    if (l>r)
      return 0;
    printf("%d ",a[l][r]);
    print(l,a[l][r]-1);
    print(a[l][r]+1,r);
}

int main(void)
{
    init();
    printf("%d\n",dfs(1,n));
    print(1,n);
    printf("\n");
    return 0;
}
