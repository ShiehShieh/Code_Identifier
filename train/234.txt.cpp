#include<iostream.h>
using namespace std;
long z[11],maxz[11],amax=0,n,m,s=0;
void fu(char *f,long p)
    {
    long i;
    for(i=0;i<=s;i++)
        if(f[p]==-1)
            {
            if(f[p-z[i]]!=-1)
                f[p]=f[p-z[i]]+1;
            }
          else
            if(f[p-z[i]]!=-1)
                if(f[p]>f[p-z[i]]+1)
                    f[p]=f[p-z[i]]+1;
    };
void dfs(char *w,long tm)
    {
    char f[512];
    long i=z[s]-1,j;
    for(j=0;j<512;j++)
        f[j]=w[j];
    while(fu(f,i+1),(f[i+1]!=-1)&&(f[i+1]<=n))
        i++;
    if(s==m-1)
        {
        if(i>=amax)
            {
            amax=i;
            for(j=0;j<m;j++)
                maxz[j]=z[j];
            };
        return;
        };
    for(j=z[s]+1;j<=i+1;j++)
        {
        z[s+1]=j;
        s++;
        dfs(f,i);
        s--;
        };
    };
int main()
    {
    long i;
    cin>>n>>m;
    char f[512];
    memset(f,-1,sizeof(f));
    f[0]=0;
    z[0]=1;
    dfs(f,0);
    for(i=0;i<m-1;i++)
        cout<<maxz[i]<<' ';
    cout<<maxz[m-1]<<endl;
    cout<<"MAX="<<amax<<endl;
    return 0;
    };
