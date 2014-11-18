#include <iostream>
using namespace std;
const int maxn=101;
int l,s,t,m,n;
int cnt;
bool b[maxn]; 
int x[maxn];
int a[maxn][11];

void sort(int n)
{int i,j,k,t;
for(i=1;i<=n;i++)
{k=i;
for(j=i+1;j<=n;j++)
if(x[j]<x[k]) k=j;
t=x[i]; x[i]=x[k]; x[k]=t;
}
}
bool can(int v)
{if(v<0) return false;
if(v>=s*s-s) return true;
return b[v]; 
}

int main()
{int i,j,k;
cin>>l>>s>>t>>m;
for(i=1;i<=m;i++) cin>>x[i];
sort(m);
n=m; while(x[n]>l) n--;
if(s==t)
{cnt=0;
for(i=1;i<=n;i++)
if(x[i]%s==0)cnt++;
cout<<cnt; return 0;
}
memset(b,false,sizeof(b));
b[0]=true;
bool flag=false;
for(i=1;i<=90;i++)
for(j=s;j<=t;j++)
{
                 if(i-j<0) flag=false;
                 else flag=b[i-j];
                 b[i]=b[i]|flag;
                 }
                 for(i=0;i<=n;i++)
                 for(j=0;j<t;j++) 
                 a[i][j]=n+1; 
                 x[0]=0; a[0][0]=0;
                 for(i=1;i<=n;i++)
                 for(j=0;j<t;j++)
                 if(x[i]-j<=x[i-1])
                 a[i][j]=a[i-1][j-x[i]+x[i-1]];
                 else
                 {for(k=0;k<t;k++)
                 if(can(x[i]-j-x[i-1]+k)&&a[i-1][k]<a[i][j])
                 a[i][j]=a[i-1][k];
                 if(j==0) a[i][j]++;
                 }
cnt=n+1;
for(i=0;i<t;i++)cnt=min(cnt,a[n][i]);
cout<<cnt;
return 0;
} 

