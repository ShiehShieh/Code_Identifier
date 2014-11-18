#include<iostream>
using namespace std;
int i,k,c=2,n,m,q,p,am[5000][2],ap[5000][2],ans[5000];
long long j=1;
int main()
{
    cin>>n>>m>>p;
    for(i=1;i<=5000;i++) ans[i]=-1;
    for(i=1;i<=m;i++) cin>>am[i][1]>>am[i][2];
    for(i=1;i<=p;i++) cin>>ap[i][1]>>ap[i][2];
    ans[am[1][1]]=j;j=j+1;
    for(i=1;i<=m;i++)
    {
                     if((ans[am[i][1]]!=-1) && (ans[am[i][2]]!=-1)) 
                     {
                                           if(ans[am[i][1]]<ans[am[i][2]]) 
                                           {
                                                                           q=ans[am[i][2]];
                                                                           for(k=1;k<=n;k++) if(ans[k]==q) ans[k]=ans[am[i][1]];
                                           }
                                           else 
                                           {
                                                q=ans[am[i][1]];
                                                for(k=1;k<=n;k++) if(ans[k]==q) ans[k]=ans[am[i][2]];
                                           }
                     }
                     else
                     {
                         if(ans[am[i][1]]!=-1) 
                         {
                                               ans[am[i][2]]=ans[am[i][1]];
                         }
                         else
                         {
                             if(ans[am[i][2]]!=-1) 
                             {
                                                   ans[am[i][1]]=ans[am[i][2]];
                             }
                             else
                             {
                                 ans[am[i][1]]=j;
                                 ans[am[i][2]]=j;
                                 j=j+1;
                             }
                         }
                     }
    }   
    for(i=1;i<=n;i++) 
    {
                      if(ans[i]==-1) ans[i]=j;
                      j=j+1;
    }                              
    for(i=1;i<=p;i++)
    {
                     if (ans[ap[i][1]]==ans[ap[i][2]]) cout<<"Yes"<<endl;
                     else cout<<"No"<<endl;
    }
    return 0;
}
