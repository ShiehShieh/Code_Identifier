#include<cstdio>
#include<queue>
#include<stack>
#include<fstream>
#include<vector>
using namespace std;
const int N = 201;
int d[N],low[N];
enum COLOR { WHITE,GRAY,BLACK } color[N];
vector<int> adj[N];
void dfs(int u,int p,stack<int>&stk,int t)
{
    color[u] = GRAY;
    d[u] = low[u] = t;
    stk.push(u);
    for(int v(0);v<(int)adj[u].size();++v)
       if(color[adj[u][v]]==WHITE)
       {
           dfs(adj[u][v],u,stk,t+1);
           low[u] = min(low[u],low[adj[u][v]]);
       }
       else if(color[adj[u][v]]==GRAY&&adj[u][v]!=p)
            low[adj[u][v]]=min(low[adj[u][v]],d[p]);
    color[u] = BLACK;
    if(d[u]==low[u])
    {
        while(true)
        {
          int s(stk.top());
          stk.pop();
          if( s==u ) break;
        }
    }
}
void tarjan(int n)
{
    for(int i=1;i<=n;++i) color[i]=WHITE;
    stack<int> stk;
    int nums(0);
    for(int i=1;i<=n;++i)
       if(color[i]==WHITE)
       {
           ++nums;
           dfs(i,-1,stk,1);
       }
    printf("%d\n",nums);
}
int main()
{
   int n,m;
   while(scanf("%d",&n)!=EOF)
   {
       for(int i=1;i<=n;++i) adj[i].clear();
       for(int i=1;i<=n;++i)
         while(scanf("%d",&m),m!=0)
           adj[i].push_back(m);
       tarjan(n);
   }
   return 0;
}
