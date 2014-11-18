#include<iostream>
using namespace std;
int T,M,t[101],v[101],f[1001][1001];
int max(int a,int b){return a>b?a:b;}
int main()
{
 cin >> T >> M;

 for(int i = 0;i < M;i++)
  cin >> t[i] >> v[i];
 
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
    if(j >= t[i])
    {
     f[i-1][j-t[i]] = f[i-1][j-t[i]] + v[i];
     f[i][j] = max(f[i-1][j],f[i-1][j-t[i]]);
    }
    else f[i][j] = f[i-1][j];
   }
  }
 cout << f[M-1][T] << endl;
}
