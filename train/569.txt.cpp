#include <iostream>
#define MAXN 200
using namespace std;
int C[MAXN+1],U[MAXN+1],W[MAXN+1][MAXN+1],sin[MAXN+1],sin1[MAXN+1],sout[MAXN+1],s[MAXN+1],n,p;
bool G[MAXN+1][MAXN+1],used[MAXN+1];
int main(){
int i,j,k,x,y;
bool f=true;
cin>>n>>p;
for(i=1;i<=n;++i)
cin>>C[i]>>U[i];
for(i=1;i<=p;++i){
cin>>x>>y;
cin>>W[x][y];
G[x][y]=true;
sin[y]++; sout[x]++; sin1[y]++;
}
for(i=1;i<=n;++i){
                  for(j=1;j<=n;++j)
                  if(sin[j]==0 && !used[j])
                  break;
                  s[i]=j; used[j]=true;
                  for(k=1;k<=n;++k)
                  if(G[j][k])
                  sin[k]--;
                  }
                  for(i=1;i<=n;++i){
                                    for(j=1;j<=n;++j)
                                    if(G[j][s[i]])
                                    C[s[i]]+=W[j][s[i]]*C[j];
                                    if(sin1[s[i]]!=0)
                                    C[s[i]]-=U[s[i]];
                                    if(sout[s[i]]>0 && C[s[i]]<=0)
                                    C[s[i]]=0;
                                    }
                                    for(i=1;i<=n;++i)
                                    if(sout[i]==0 && C[i]>0){
                                                  cout<<i<<' '<<C[i]<<endl;
                                                  f=false;
                                                  }
                                                  if(f) cout<<"NULL"<<endl;
                                                  }
