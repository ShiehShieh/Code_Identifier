#include<iostream>
using namespace std;
long n,m,p;
long rank[5001]={0},par[5001]={0};
void set()
{
     long i;
     for(i=1;i<=n;i++)
     {
      rank[i]=1;
      par[i]=i;
     }
}
long q(long cur)
{
     long in,b,x;
     for(in=cur;par[in]!=in;in=par[in]);
     for(b=cur;par[b]!=b;x=par[b],par[b]=in,b=x);
     return in;
}
void merge(long a,long b)
{
     a=q(a);
     b=q(b);
     if(rank[a]>rank[b])
     {
      rank[a]++;
      par[b]=a;
     }
     else
     {
      rank[b]++;
      par[a]=b;
     }
}
int main()
{
    long i;
    long a,b;
    cin>>n>>m>>p;
    set();
    for(i=0;i<m;i++)
    {
     cin>>a>>b;
     merge(a,b);
    }
    for(i=0;i<p;i++)
    {
     cin>>a>>b;
     if(q(a)==q(b)) cout<<"Yes"<<endl;
     else           cout<<"No"<<endl;
    }
}

