#include<iostream>
using namespace std;
int n,finish,dp[88001];
struct data
{
       int s,f,w;
}a[10001];
struct node
{
       int start,finish;
       int min;
}tree[500001];
void init()
{
     int i,base;
     cin>>n>>base>>finish;
     finish-=(base-1);
     for (i=1;i<=n;i++)
     {
         cin>>a[i].s>>a[i].f>>a[i].w;
         a[i].s-=(base-1);
         a[i].f-=(base-1);
         if ( a[i].s<1 ) a[i].s=1;
         if ( a[i].f>finish ) a[i].f=finish;
     }
     for (i=1;i<=finish;i++) dp[i]=INT_MAX;
}
int comp(const void *a,const void *b)
{
    if ( (*(data *)a).s>(*(data *)b).s )
     return(1);
    else
    {
        if ( (*(data *)a).s==(*(data *)b).s )
        {
             if ( (*(data *)a).f>(*(data *)b).f )
              return(1);
             else
              return(-1);
        }
        else
         return(-1);
    }
}
int answer(int s,int f,int root)
{
    int mid=(tree[root].start+tree[root].finish)/2;
    if ( s==tree[root].start && f==tree[root].finish )
     return ( tree[root].min );
    else
    {
        if ( f<=mid )
         return ( answer(s,f,root*2) );
        else
        {
            if ( s>=mid+1 )
             return( answer(s,f,root*2+1) );
            else
            return( min(answer(s,mid,root*2),answer(mid+1,f,root*2+1)) );
        }
    }
}
int choose(int x,int y)
{
    return( min(x,y) );
}
void insert(int x,int num,int root)
{
     int mid=(tree[root].start+tree[root].finish)/2;
     if ( tree[root].start<tree[root].finish )
     {
          if ( x<=mid )
           insert(x,num,root*2);
          else
           insert(x,num,root*2+1);
          tree[root].min=choose(tree[root*2].min,tree[root*2+1].min);
     }
     else
      tree[root].min=num;
}
void work()
{
     int i,temp;
     for (i=1;i<=n;i++)
     {
         temp=answer(a[i].s-1,a[i].f-1,1);
         if ( dp[a[i].f]>temp+a[i].w && temp!=INT_MAX )
         {
              dp[a[i].f]=temp+a[i].w;
              insert(a[i].f,dp[a[i].f],1);
         }
     }
     if ( dp[finish]==INT_MAX )
      dp[finish]=-1;
     cout<<dp[finish];
}
void build(int s,int f,int root)
{
     int mid=(s+f)/2;
     tree[root].start=s;tree[root].finish=f;
     if (  s<f )
     {
           build(s,mid,root*2);
           build(mid+1,f,root*2+1);
           tree[root].min=choose(tree[root*2].min,tree[root*2+1].min);
     }
     else
     {
         if ( s==0 )
         tree[root].min=0;
         else
         tree[root].min=INT_MAX;
     }
}
main()
{
      init();
      qsort(&a[1],n,sizeof(a[1]),comp);
      build(0,finish,1);
      work();
}
