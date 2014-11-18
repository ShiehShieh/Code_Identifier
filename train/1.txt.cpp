#include <iostream>
#include <limits.h>
using namespace std;
int const N=101;
struct node
{int left,right;
 int num,cm;
}tree[N];
int f[N][N][N]={0};
int n,k;
void visit (int root,int grand,int build_num,int km)
{int i,j,m,temp;
 if(root==0)
   return ;
 if(f[root][grand][build_num]>=0)
   return ;
// if(tree[root].left==0&&tree[root].right==0)
//   return ;
 m=INT_MAX;
 for(i=0;i<=build_num;i++)
    {visit(tree[root].left,grand,i,km+tree[tree[root].left].cm);
     visit(tree[root].right,grand,build_num-i,km-tree[root].cm+tree[tree[root].right].cm);
     m=min(m,f[tree[root].left][grand][i]+f[tree[root].right][grand][build_num-i]+km*tree[root].num);
     //if(temp<m)
      // m=temp;
    }
 for(i=0;i<build_num;i++)
    {visit(tree[root].left,root,i,tree[tree[root].left].cm);
     visit(tree[root].right,grand,build_num-i-1,km-tree[root].cm+tree[tree[root].right].cm);
     m=min(m,f[tree[root].left][root][i]+f[tree[root].right][grand][build_num-i-1]);
     //if(temp<m)
      // m=temp;
    }
 f[root][grand][build_num]=m;
 return ;
}
int main ()
{int i,j,h,a,b,c;
 cin>>n>>k;
 for(i=1;i<=n;i++)
    {cin>>a>>b>>c;
     tree[i].num=a;
     tree[i].cm=c;
     tree[i].right=tree[b].left;
     tree[b].left=i;
    }
 for(i=1;i<=n;i++)
    for(j=0;j<=n;j++)
       for(h=0;h<=k;h++)
          f[i][j][h]=-1;
 visit(tree[0].left,0,k,tree[tree[0].left].cm);
 cout<<f[tree[0].left][0][k];
 return 0;
}
