#include <iostream>
#include <cstring>
using namespace std;
long k,w;
long f[10][1050][201]={0};
/*long max(long a,long b)
{
     if(a>b) return a;
     else    return b;
}*/
void add(long c[],long a[],long b[])
{
     long i;
     c[0]=max(a[0],b[0]);
     for(i=1;i<=c[0];i++)
     {
      c[i]=a[i]+b[i];
      c[i+1]+=c[i]/10;
      c[i]%=10;
     }
     while(c[c[0]+1])
     {
      c[0]++;
      c[c[0]+1]+=c[c[0]]/10;
      c[c[0]]%=10;
     }
}
void print(long a[])
{
     long i;
     for(i=a[0];i>=1;i--)
      cout<<a[i];
     cout<<endl;
}
int main()
{
    long limit;
    long i,j,t;
    long blank[201]={0};
    long ans[201]={0};
    blank[0]=1;
    cin>>k>>w;
    limit=w%k; if(limit==0) limit=k;
    w=(w-limit)/k;
    limit=(1<<limit)-1;
 
     for(i=0;i<=limit;i++)
     {
      f[1][i][0]=1;
      f[1][i][1]=1;
     }
     if(w<=1)
     {
      f[1][0][0]=1;
      f[1][0][1]=0;
     }
    for(i=2;i<=w+1;i++)
    {
     if(i<w)
     { 
      f[i%2][0][0]=1; 
      f[i%2][0][1]=1;
     }
     else
     {
      f[i%2][0][0]=1;
      f[i%2][0][1]=0;
     }
     for(j=1;j<=(1<<k)-1;j++)
     { 
       memcpy(f[i%2][j],blank,sizeof(blank));
       add(f[i%2][j],f[(i-1)%2][j-1],f[i%2][j]);   
       if(j>1)
        add(f[i%2][j],f[i%2][j-1],f[i%2][j]); 
     }
    }
    for(i=0;i<=(1<<k)-1;i++)
     add(ans,ans,f[(w+1)%2][i]);
    for(i=ans[0];i>=1;i--)
     cout<<ans[i];
    cout<<endl;
    return 0;
}
