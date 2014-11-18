#include<cstdio>
#include<iostream>
using namespace std;
int n,m,a[200001],be[8000001],l[8000001],r[8000001],lc[8000001],rc[8000001],num=0;
void build(int x,int y)//&sup1;&sup1;&frac12;¨&Iuml;&szlig;&para;&Icirc;&Ecirc;÷ 
{int v;
 num++;
 v=num;
 l[v]=x;
 r[v]=y;
 if(x!=y)
   {lc[v]=num+1;
    build(x,(x+y)/2);
    rc[v]=num+1;
    build((x+y)/2+1,y);
   }
}
void ins(int v)//&ETH;&THORN;&cedil;&Auml;&Iuml;&szlig;&para;&Icirc;&Ecirc;÷ 
{if(l[v]==r[v])
   be[v]=a[l[v]];
 else
   {ins(lc[v]);
    ins(rc[v]);
    be[v]=max(be[lc[v]],be[rc[v]]);
   }
}
int ans(int x,int y,int v)
{int best=-INT_MAX;
 if(x<=l[v]&&y>=r[v])
   return be[v];
 else
   {if(x<=(l[v]+r[v])/2)
      best=max(best,ans(x,y,lc[v]));
    if(y>(l[v]+r[v])/2)
      best=max(best,ans(x,y,rc[v]));
   }
 return best;
}
int main()
{int x,y,i;
 scanf("%d",&n);
 for(i=1;i<=n;i++)
   scanf("%d",&a[i]);
 build(1,n);
 ins(1);
 cin>>m;
 for(i=1;i<=m;i++)
   {scanf("%d%d",&x,&y);
    printf("%d\n",ans(x,y,1));
   }
 scanf("%d",&n);
 return 0;
}
    
    
 

