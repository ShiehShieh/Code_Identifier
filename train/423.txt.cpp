#include <iostream>
#include <cstring>
using namespace std;
int n,s,t,i,x,y,L[10010],fa[10010],l[10010],num[10010],Time[10010];
bool use[10010];
char S[300];
int main()
{
  cin >> n >> s >> t;
  for (i=1;i<=n;i++)
  {
    scanf("%d%d%s",&x,&y,&S);
    l[x] = strlen(S);
    fa[x] = y;
    num[y]++;
  }
  use[s] = 1;
  L[s] = l[s];
  while (s!=0)
  {
    Time[fa[s]] = Time[s]+num[fa[s]];
    L[fa[s]] = L[s]+l[fa[s]];
    use[fa[s]] = 1;
    s = fa[s];
  }
  L[t] = l[t];
  while (!use[fa[t]])
  {
    Time[fa[t]] = Time[t]+num[fa[t]];
    L[fa[t]] = L[t]+l[fa[t]];
    t = fa[t];
  }
  Time[fa[t]] += Time[t];
  L[fa[t]] += L[t];
  t = fa[t];
  printf("%d\n%d\n",L[t],Time[t]);
  cin >> n;
  return 0;
}

