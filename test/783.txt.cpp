#include<iostream>
using namespace std;
int T,M,t[20000],f[31][20000];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
 cin >> T >> M;
 for(int i = 0;i < M;i++) cin >> t[i];
 for(int i = 0;i < M;i++)
   for(int j = 0;j <= T;j++)
   {
    if(i == 0)
    {
     if(j >= t[i]) f[i][j] = t[i];
     else f[i][j] = 0;
    }
    else
    {
     if(j >= t[i]) f[i][j] = max(f[i-1][j],f[i-1][j-t[i]]+t[i]);
     else f[i][j] = f[i-1][j];
    }
   }
  cout << T - f[M-1][T] << endl;
}

