#include <iostream>
using namespace std;
typedef struct TNode
{int l,r;
};
TNode tree[301];
int data[301];
int f[301][301]={0};
int n,m;
int DP(int x,int y)
{if (x==-1) return 0;
 if (y==0) return 0;
 if (f[x][y]!=0) return f[x][y];
 f[x][y]=DP(tree[x].r,y);
 int z,c,d;
 for (z=0;z<y;z++){
      c=DP(tree[x].l,z);
      d=DP(tree[x].r,y-z-1);
      f[x][y]=max(c+d+data[x],f[x][y]);
                    }
 return f[x][y];
}
int main()
{int i,j,a;
 cin>>n>>m;
 for (i=1;i<=n;i++){
      cin>>a>>data[i];
      tree[i].r=tree[a].l;
      tree[a].l=i;
                   }
 tree[0].r=-1;
 for (i=1;i<=n;i++){
      if (tree[i].l==0) tree[i].l=-1;
      if (tree[i].r==0) tree[i].r=-1;
                   }
 cout<<DP(0,m+1);
 return 0;
}

