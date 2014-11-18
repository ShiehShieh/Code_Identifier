#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
       int start,finish;
       int num,length;
}tree[500001];
struct data
{
       int num,add,rank;
       int s,f;
}p[100002];
int n,m,a[100002],l[100002],r[100002],fact;
int comp(const void *a,const void *b)
{
    if ( (*(data*)a).num>(*(data*)b).num ) 
     return(1);
    else
     return(-1);
}
void init()
{
     int i;
     scanf("%d %d",&n,&m);
     //cin>>n>>m;
     for (i=1;i<=n;i++)
     {
         scanf("%d",&p[i].num);
         //cin>>p[i].num;
         p[i].add=i;
     }
     qsort(&p[1],n,sizeof(p[1]),comp);
     
     p[1].rank=1;
     for (i=2;i<=n;i++)
     {
         if ( p[i].num!=p[i-1].num )
          p[i].rank=p[i-1].rank+1;
         else
          p[i].rank=p[i-1].rank;
     }
     fact=p[n].rank;
     p[0].f=1;
     for (i=1;i<=n;i++)
     {
         p[i].f=p[i-1].f;
         while ( p[i].f<=n && p[i].num>=p[ p[i].f ].num-m ) 
          p[i].f++;
         p[i].f--;
         //p[i].f=p[ p[i].f ].rank;
     }
     p[n+1].s=n;
     for (i=n;i>=1;i--)
     {
         p[i].s=p[i+1].s;
         while ( p[i].s>=1 && p[i].num<=p[ p[i].s ].num+m ) 
          p[i].s--;
         p[i].s++;
         //p[i].s=p[ p[i].s ].rank;
     }
     for (i=1;i<=n;i++) 
     {
         a[ p[i].add ]=p[i].rank;
         l[ p[i].add ]=p[p[i].s].rank;
         r[ p[i].add ]=p[p[i].f].rank;
     }
}
void insert1(int x,int k,int root)
{
     int mid=(tree[root].start+tree[root].finish)/2;
     tree[root].num+=k;tree[root].num%=198964;
     if ( tree[root].start<tree[root].finish )
     {
          if ( x<=mid )
           insert1(x,k,root*2);
          else
           insert1(x,k,root*2+1);
     }
}
void insert2(int x,int k,int root)
{
     int mid=(tree[root].start+tree[root].finish)/2;
     if ( tree[root].start==tree[root].finish )
      tree[root].length=k;
     else
     {
         if ( x<=mid )
          insert2(x,k,root*2);
         else
          insert2(x,k,root*2+1);
         tree[root].length=max(tree[root*2].length,tree[root*2+1].length);
     }
}
int answer1(int s,int f,int root)
{
    int mid=(tree[root].start+tree[root].finish)/2;
    if ( s==tree[root].start && f==tree[root].finish )
     return( tree[root].num );
    else
    {
        if ( f<=mid )
         return( answer1(s,f,root*2) );
        else
        {
            if ( s>=mid+1 )
             return( answer1(s,f,root*2+1) );
            else
             return( answer1(s,mid,root*2)+answer1(mid+1,f,root*2+1) )%198964;
        }
    }
}
int answer2(int s,int f,int root)
{int mid=(tree[root].start+tree[root].finish)/2;
    if ( s==tree[root].start && f==tree[root].finish )
     return( tree[root].length );
    else
    {
        if ( f<=mid )
         return( answer2(s,f,root*2) );
        else
        {
            if ( s>=mid+1 )
             return( answer2(s,f,root*2+1) );
            else
             return(max(answer2(s,mid,root*2),answer2(mid+1,f,root*2+1)));
        }
    }
}
void build(int s,int f,int root)
{
     tree[root].start=s;tree[root].finish=f;
     tree[root].length=0;tree[root].num=0;
     if ( s<f )
     {
          build(s,(s+f)/2,root*2);
          build((s+f)/2+1,f,root*2+1);
     }
}
void work()
{
     int i,j,temp;
     for (i=1;i<=n;i++)
     {
         insert1(a[i],answer1(l[i],r[i],1)+1,1);
         insert2(a[i],answer2(l[i],r[i],1)+1,1);
     }
     
     if ( answer2(1,fact,1)==1 )
          cout<<0<<endl<<0;
     else
     {
         temp=answer1(1,fact,1);
         while ( temp<n )
           temp+=198964;
         temp-=n;
         cout<<temp%198964<<endl<<answer2(1,fact,1);
     }
}
main()
{
      init();
      build(1,fact,1);
      work();
}


