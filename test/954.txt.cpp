#include <iostream>
using namespace std;

int f[101][1001];
int t[101];
int v[101];
int n,m;

void dp(){
    int i,j;
    for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
        f[i][j]=f[i-1][j];
        if(t[i]<=j&&f[i-1][j-t[i]]+v[i]>f[i][j])
          f[i][j]=f[i-1][j-t[i]]+v[i];
      }
    }
    printf("%d\n", f[n][m]);
}

int main()
{
    int i;
    
    scanf("%d %d", &m, &n);
    for(i=1;i<=n;i++)
      scanf("%d %d", &t[i], &v[i]);
    dp();
    
    return 0;
}

