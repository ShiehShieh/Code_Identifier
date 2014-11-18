#include<iostream>//laiyao1 v1.0beta
using namespace std;
struct std
{int left,right,w,d;
}tree[102];
int n,m,f[102][102][102];
int dfs(int x,int y,int z,int s)
{int i;
 if(z==n+1)
   return 0;
 if(f[x][y][z]!=-1)
   return f[x][y][z];
 f[x][y][z]=INT_MAX;
 for(i=0;i<=z;i++)//不在X节点建伐木站 
   f[x][y][z]=min(f[x][y][z],dfs(tree[x].left,y,i,s+tree[x].d)+dfs(tree[x].right,y,z-i,s)+tree[x].w*(s+tree[x].d));
 for(i=0;i<=z-1;i++)//在X节点建伐木站  
   f[x][y][z]=min(f[x][y][z],dfs(tree[x].left,x,i,0)+dfs(tree[x].right,y,z-1-i,s));
 return f[x][y][z];
}   
int main()
{int i,t,j,k;
 cin>>n>>m;
 for(i=0;i<=n+1;i++)
   {tree[i].left=n+1;
    tree[i].right=n+1;
   }
 for(i=1;i<=n;i++)
   {cin>>tree[i].w>>t>>tree[i].d;
    tree[i].right=tree[t].left;
    tree[t].left=i;
   }
 for(i=0;i<=n;i++)
   for(j=0;j<=n;j++)
     for(k=0;k<=m;k++)
       f[i][j][k]=-1;
 cout<<dfs(tree[0].left,0,m,0)<<endl;
 return 0;
}
    
    
 

