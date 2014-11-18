#include<iostream>
using namespace std;
int T,M,t[101],v[101],f[101][1001];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
 cin >> M >> T;
 for(int i = 0;i < M;i++)cin >> v[i] >> t[i];
 for(int i = 0;i < M;i++)
   for(int j = 0;j <= T;j++)
   {
    if(i == 0)
    {
     if(j >= t[i]) f[i][j] = v[i];
     else f[i][j] = 0;
    }
    else
    {
     if(j >= t[i]) f[i][j] = max(f[i-1][j],f[i-1][j-t[i]]+v[i]);
     else f[i][j] = f[i-1][j];
    }
   }
  cout << f[M-1][T] << endl;
}
