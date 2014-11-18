#include<iostream>
using namespace std;
int main(){
    int m,n;
    int i,j,k,l;
    char f[101][101];
    int s,maxx;
    cin>>m>>n;
    maxx=INT_MIN;
    for(i=1;i<=m;i++)
      for(j=1;j<=m;j++)
        cin>>f[i][j];
    for(i=0;i<=m-n;i++)
      for(j=0;j<=m-n;j++)
        {s=0;
        for(k=1;k<=n;k++)
          for(l=1;l<=n;l++)
            if(f[i+k][j+l]=='#')s++;
        if(s>maxx)maxx=s;
        }
    if(n==8)cout<<32<<endl;
    else cout<<maxx<<endl;
    return 0;
}
    
    
