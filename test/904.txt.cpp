#include<iostream>
using namespace std;
int a[1001],b[1001];
bool t1[1001],t2[1001];
int main(){
    int m,n,k,l,d;
    int i,j;
    int x,y,p,q;
    int maxx,s;
    cin>>m>>n>>k>>l>>d;
    for(i=1;i<=d;i++)
      {cin>>x>>y>>p>>q;
      if(x==p)b[min(y,q)]++;
      else a[min(x,p)]++;
      }
    for(i=1;i<=k;i++)
      {maxx=0;
      for(j=1;j<=m;j++)
        if(a[j]>a[maxx])maxx=j;
      t1[maxx]=true;
      a[maxx]=-1;
      }
    for(i=1;i<=l;i++)
      {maxx=0;
      for(j=1;j<=n;j++)
        if(b[j]>b[maxx])maxx=j;
      t2[maxx]=true;
      b[maxx]=-1;
      }
    s=0;
    for(i=1;i<=m;i++)
      if(t1[i]==true)
        {if(s==k-1){cout<<i;break;}
        else {cout<<i<<' ';
             s++;}
        }
      
    cout<<endl;
    s=0;
    for(i=1;i<=n;i++)
      if(t2[i]==true)
        {if(s==l-1){cout<<i;break;}
        else {cout<<i<<' ';
             s++;}
        }
    return 0;
}

