#include<iostream>
using namespace std;
int m,n;
long long d[101][501],f[101][501];
int p[101][501];

void input()
 { cin>>m>>n;
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
     cin>>d[i][j];
    for(int i=1;i<=n;i++)
     f[1][i]=d[1][i];
}
void dp()
 { for(int i=2;i<=m;i++)
     {for(int j=1;j<=n;j++){f[i][j]=f[i-1][j]+d[i][j];p[i][j]=j;}
       for(int j=2;j<=n;j++)if(f[i][j]>f[i][j-1]+d[i][j]){f[i][j]=f[i][j-1]+d[i][j];p[i][j]=j-1;}
       for(int j=n-1;j>=1;j--)if(f[i][j]>f[i][j+1]+d[i][j]){f[i][j]=f[i][j+1]+d[i][j];p[i][j]=j+1;}
     }
 }
 void output(int i,int j)
   { if(i==1){cout<<j<<endl;return;}
     if(p[i][j]==j)output(i-1,j);
     else output(i,p[i][j]);
     cout<<j<<endl;
   }
 void output()
  { long long mim=f[m][1];int j=1;
      for(int i=2;i<=n;i++)
       if(mim>f[m][i]){mim=f[m][i];j=i;}
       
       output(m,j);
  }
 int main()
 { input();
    dp();
    output();
    return 0;
}
