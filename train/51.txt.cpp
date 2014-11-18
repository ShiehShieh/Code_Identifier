#include <iostream>
using namespace std;
//ifstream cin  ("3.in");
//ofstream cout ("3.out");

int data[53][53],f[120][53][53];
int n,m,h;

void init ()
{
     cin >> n >> m;
     for (int i = 1;i <= n;i ++)
      for (int j = 1;j <= m;j ++) cin >> data[i][j];
     return ;
}

void work ()
{
     memset(f,0,sizeof(f));
     for (int k = 2;k <= n + m - 1;k ++)
      {
      for (int i = 1;i <= min(n, k);i ++)
       for (int j = 1;j <= min(n,k);j ++)
         {
           for (int di = 0; di <=1;di ++)
            for (int dj = 0;dj <= 1;dj ++)
             {
               int x1 = i - di, x2 = j - dj;
               if ((x1 < 0) || (x2 < 0)) continue;
               if ( x1 == x2) continue;
               int s = f[k - 1][x1][x2] + data[i][k + 1 - i] + data[j][k + 1 - j];
               f[k][i][j] >?= s;
            }
         }
      }
     

     
     cout << f[n +m - 1][n][n] << endl;
     return ;
     
}

int main ()
{
    init ();
    work ();
    return 0;
}

