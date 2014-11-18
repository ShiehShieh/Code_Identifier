#include<iostream>
using namespace std;
struct node
{
       int s,f;
}a[10001],temp[10001];
int n,ok[10001];
struct data
{
       int start,finish;
       int num;
}tree[40001];
int comp(const void *a,const void *b)
{
    if ( (*(node *)a).s>(*(node *)b).s )
      return(1);
    else
     return(-1);
}
void init()
{
     int i,x,y,m,j;
     cin>>m;
     for (i=1;i<=m;i++)
      cin>>temp[i].s>>temp[i].f;
     for (i=1;i<=m;i++)
     {
         
         for (j=1;j<=m;j++)
         {
             if ( j!=i )
             {
                  if ( temp[j].s<=temp[i].s && temp[i].f<=temp[j].f )
                   ok[j]=1;
             }
         }
     }
     for (j=1;j<=m;j++)
      if ( ok[j]==0 )
      {
           n++;
           a[n]=temp[j];
      }
     qsort(&a[1],n,sizeof(a[1]),comp);
}
void insert(int x,int root)
{
     int mid=(tree[root].start+tree[root].finish)/2;
     tree[root].num++;
     if ( tree[root].start<tree[root].finish )
     {
          if ( x<=mid )
           insert(x,root*2);
          else
           insert(x,root*2+1);
     }
}
int answer(int s,int f,int root)
{
    int mid=(tree[root].start+tree[root].finish)/2;
    if ( s==tree[root].start && f==tree[root].finish )
     return(tree[root].num);
    else
    {
        if ( f<=mid )
         return(answer(s,f,root*2));
        else
        {
            if ( s>=mid+1 )
             return(answer(s,f,root*2+1));
            else
                return( answer(s,mid,root*2)+answer(mid+1,f,root*2+1));
        }
    }
}
void action()
{
     int i,j,k,num=0;
     for (i=n;i>=1;i--)
     {
         j=answer(a[i].s,a[i].f,1);
         k=a[i].s;
         while ( j<2 )
         {
               if ( answer(k,k,1)==0 )
               {
                    insert(k,1);
                    j++;
                    num++;
               }
               k++;
         }
     }
     cout<<num;
}
void  mark(int s,int f,int root)
{
     int mid=(s+f)/2;
     tree[root].start=s;tree[root].finish=f;
     tree[root].num=0;
     if ( s<f )
     {
          mark(s,mid,root*2);
          mark(mid+1,f,root*2+1);
     }     
}
main()
{
      init();
      mark(0,10000,1);
      action();
}


