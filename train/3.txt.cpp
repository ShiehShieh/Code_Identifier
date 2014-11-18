#include<iostream>
using namespace std;
int n,m,w[101],f[101],len[101];
int l[101],r[101],dp[101][101][51];
void init()
{
     int i;
     cin>>n>>m;
     for (i=1;i<=n;i++)
      cin>>w[i]>>f[i]>>len[i];
     memset(l,-1,sizeof(l));
     memset(r,-1,sizeof(r));
     memset(dp,-1,sizeof(dp));
}
void build(int root)
{
     int i,temp;
     for (i=1;i<=n;i++)
      if ( f[i]==root )
       break;
     if ( i<=n )
     {
          l[root]=i;
          temp=i;
          for (i=i+1;i<=n;i++)
          {
              if ( f[i]==root )
              {
                   r[temp]=i;
                   temp=i;
              }
          }
          for (i=1;i<=n;i++)
           if ( f[i]==root )
           {
                len[i]+=len[root];
                build(i);
           }
     }
}
int work(int x,int come,int rest)
{
    int min,i,temp,t;
    if ( dp[x][come][rest]!=-1 )
     return( dp[x][come][rest] );
    if ( l[x]==-1 && r[x]==-1 )
    {
         if ( rest>=1 )
         return(0);
         else
         return( w[x]*(len[x]-len[come]) );
    }
    else
    {
        temp=w[x]*(len[x]-len[come]);
        if ( l[x]!=-1 && r[x]==-1)
         temp+=work(l[x],come,rest);
        if ( r[x]!=-1 && l[x]==-1 )
         temp+=work(r[x],come,rest);
        if ( l[x]!=-1 && r[x]!=-1 )
        {
             t=300000000;
             for (i=0;i<=rest;i++)
              if ( t>work(l[x],come,i)+work(r[x],come,rest-i) )
               t=work(l[x],come,i)+work(r[x],come,rest-i);
             temp+=t;
        }
        min=temp;
        if ( rest>=1 )
        {
             temp=0;
             if ( l[x]!=-1 && r[x]==-1 )
                  temp+=work(l[x],x,rest-1);
             if ( l[x]==-1 && r[x]!=-1 )
                temp+=work(r[x],come,rest-1);
             if ( l[x]!=-1 && r[x]!=-1 )
             {
                  temp=300000000;
                  for (i=0;i<=rest-1;i++)
                  {
                      if ( temp>work(l[x],x,i)+work(r[x],come,rest-1-i) )
                       temp=work(l[x],x,i)+work(r[x],come,rest-1-i);
                  }
             }
             if ( min>temp )
              min=temp;
        }
        dp[x][come][rest]=min;
        return(min);
    }
}
main()
{
      init();
      build(0);
      cout<<work(0,0,m);
}

