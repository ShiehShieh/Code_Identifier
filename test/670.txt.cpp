/*  Vijos P1205  */

#include <iostream>
using namespace std;

int n;
int a[3010];

int k[3001];
int f[3001];
int ans;

void init()
{
     cin>>n;
     for (int i=1;i<=n;i++)
       scanf("%d",&a[i]);
     
     a[0]=INT_MAX;
     k[0]=1;
     ans=(-1);
}

void dp()
{
    for (int i=1;i<=n;i++)
      {
          for (int j=0;j<i;j++)
            {
                   if (a[j]==a[i])
                     {
                             k[i]=0;
                             continue;
                     }
                   if (a[j]>a[i] && f[i]<=f[j]+1)
                     {
                             if (f[i]==f[j]+1)
                                k[i]=(k[i]+k[j])%10000;
                             else
                                k[i]=k[j];
                             f[i]=f[j]+1;
                     }
            }
          ans=max( ans , f[i] );
      }
}

void print()
{
    int kind=0;
    for (int i=1;i<=n;i++)
       if (f[i]==ans)
         kind=(kind+k[i])%10000;
    cout<<ans<<" "<<kind<<endl;
}

int main(void)
{
    init();
    dp();
    print();
    return 0;
}
