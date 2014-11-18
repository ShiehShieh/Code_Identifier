#include <iostream.h>
const int maxn = 102;
int mapA[maxn][maxn] , mapB[maxn][maxn];
int i, j, k, n, m, t;
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1};

int init()
     {
       char ch;
       cin >> m >> n >> t;
       t--;
       for (i=1;i<=n;i++)
         for (j=1;j<=m;j++)
           {
             cin >> ch;
             if ( ch == '0' ) 
               mapA[i][j] = 0;
             else 
               mapA[i][j] = 1;
           }
     }
     
void change()
     {
       for (i=0; n+1 >= i;i++)
         for (j=0; m+1 >= j;j++)
           mapB[i][j]=0;
       int sum;
       for (i=1;i <= n;i++)
         for (j=1; j<=m;j++)
           {
             sum = 0;
             for (k=0; k <= 7; k++)
               {
                 sum = sum + mapA[ i + dy[ k ] ][ j + dx[ k ] ];
               }
             if (3 == sum) mapB[i ][ j] = 1;
             else if ((2 == sum) && (mapA[i ][ j] == 1)) mapB[i ][ j] = 1;
             else mapB[i ][ j] = 0;
           }  
       for (i=0; i<=n+1; i++)
         for (j=0; j<=m+1; j++)
           mapA[i][j] = mapB[i][j];
     }
     
void print()
     {
            for (i=1; i <= n;i++)
              {
                for (j=1; j <= m;j++)
                  cout << mapA[i][j];
                cout << endl;
              }
     }
     
int main()
    {
          for (i=0; n+1 >= i;i++)
            for (j=0; m+1 >= j;j++)
              {
                mapA[i][j] = 0;
                mapB[i][j] = 0;
              }
          init();
          while (t != 0) {
            change();
            t--;
          }
          print();
    }

