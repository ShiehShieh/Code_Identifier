#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
       int flag,w;
       node *next;
}a[100001];
int n,q[100001],visit[100001],father[100001];
__int64 len[100001],num[100001],cost[100001];
void insert(int d,int x,int w)
{
     node *p;
     p=&a[d];
     while ( p->flag!=-1 )
      p=p->next;
     p->flag=x;p->w=w;
     p->next=new(node);
     p->next->flag=-1;
}
void init()
{
     int i,x,y,w;
     scanf("%d",&n);
     //cin>>n;
     for (i=1;i<=n;i++)
     {
         scanf("%d",&q[i]);
         //cin>>q[i];
         a[i].flag=-1;
     }
     for (i=1;i<=n-1;i++)
     {
         scanf("%d %d %d",&x,&y,&w);
         //cin>>x>>y>>w;
         insert(x,y,w);
         insert(y,x,w);
     }
}
void build(int root)
{
     node *p;
     __int64 k1=q[root],k2=0;
     visit[root]=1;
     p=&a[root];
     while ( p->flag!=-1 )
     {
           if ( visit[p->flag]==0 )
           {
                father[p->flag]=root;
                len[p->flag]=p->w;
                build(p->flag);
                k1+=num[p->flag];
                k2+=(cost[p->flag]+num[p->flag]*len[p->flag]);
           } 
           p=p->next;
     }
     num[root]=k1;cost[root]=k2;
     visit[root]=0;
}
void work()
{
     int i,j,flag;
     __int64 best=INT_MAX,k,length;
     best*=100000;
     for (i=1;i<=n;i++)
     {
         j=i;k=cost[i];length=0;
         while ( j!=1 )
         {
               length+=len[j];
               k=k+cost[father[j]]-cost[j]+length*(num[father[j]]-num[j])-len[j]*num[j];
               j=father[j];
         }
         if ( best>k ){best=k;flag=i;}
     }
     cout<<flag<<endl<<best;
}
main()
{
      init();
      build(1);
      work();
}

