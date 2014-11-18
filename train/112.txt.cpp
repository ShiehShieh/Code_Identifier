#include <iostream>
#include <fstream>
using namespace std;
//ifstream fin("p1518.in");
typedef __int64 i64;
const int maxn=101;
const int maxk=101;
const i64 infinity=2000000001;
typedef struct tree
{int ch,br,fa; //儿子兄弟和父亲
 int d,w; //距离和权值 
};
tree t[maxn];
i64 f[maxn][maxn][maxn];
int n,m;

i64 dp(int i,int root,int k,int total)
{int j;
 i64 s;
 if(i==-1)
    if(k==0) return 0;
    else return infinity;
 if(f[i][root][k]>=0) return f[i][root][k];
 s=infinity;
 //枚举建或不建 
 for(j=0;j<k;j++) //建 
    s=min(s,dp(t[i].ch,i,j,0)+dp(t[i].br,root,k-1-j,total));
 for(j=0;j<=k;j++) //不建
    s=min(s,(total+t[i].d)*t[i].w+dp(t[i].ch,root,j,total+t[i].d)+dp(t[i].br,root,k-j,total));
 f[i][root][k]=s;
 //cout<<s<<endl;
 return s;
}

int main()
{int i,j,l;
 cin>>n>>m;
 for(i=1;i<=n;i++)
    {cin>>t[i].w>>t[i].fa>>t[i].d;
     t[i].br=t[t[i].fa].ch;
     t[t[i].fa].ch=i;
    }
 for(i=1;i<=n;i++)
    {if(t[i].ch==0) t[i].ch=-1;
     if(t[i].br==0) t[i].br=-1;
    }
 for(i=0;i<=n;i++)
    for(j=0;j<=n;j++)
      for(l=0;l<=n;l++)
         f[i][j][l]=-1;
 cout<<dp(t[0].ch,0,m,0);
 //while(1) ;
 return 0;
}
