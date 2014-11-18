#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(A,B) (A>B?A:B)
struct Tree
{
  int son,brother;
};

bool b[301][301];
int rgt[301][301];
int tmp,n,m,i;
int f[301],s[301],root;
Tree a[301];

int ty(int root,int m)
{
  if(!root || !m)
    return 0;
  if(!b[root][m])
  {
    b[root][m]=true;
    rgt[root][m]=ty(a[root].brother,m);
    int d=ty(a[root].brother,m-1)+s[root];
    if(d>rgt[root][m])
      rgt[root][m]=d;
    for(int i=1;i<m;i++)
    {
      int tmp=ty(a[root].son,i)+ty(a[root].brother,m-i-1)+s[root];
      if(tmp>rgt[root][m])
	rgt[root][m]=tmp;
    }
  }
  return rgt[root][m];
}

int main()
{
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)
  {
    scanf("%d%d",&f[i],&s[i]);
    if(!root && !f[i])
      root=i;
    if(!a[f[i]].son)
      a[f[i]].son=i;
    else
    {
      int t=a[f[i]].son;
      while(a[t].brother)
	t=a[t].brother;
      a[t].brother=i;
    }
  }
  printf("%d\n",ty(root,m));
  return 0;
}


