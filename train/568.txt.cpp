#include <iostream>
#define MAXN 100
using namespace std;
int f[MAXN+1][MAXN+1],a[MAXN+1][MAXN+1],b[MAXN+1][MAXN+1],n;
int main(){
    int i,j,k,m;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i][0];
    for(i=0;i<n;++i)
        b[i][0]=a[(i+1)%n][0];

    for(i=1;i<n;++i)
        for(j=0;j<n;++j)
            for(k=0;k<i;++k)
                if(b[j][k]==a[(j+k+1)%n][i-k-1] &&
                        f[j][i]<f[j][k]+f[(j+k+1)%n][i-k-1]+a[j][k]*b[j][k]*b[(j+k+1)%n][i-k-1]){
                    f[j][i]=f[j][k]+f[(j+k+1)%n][i-k-1]+a[j][k]*b[j][k]*b[(j+k+1)%n][i-k-1];
                    a[j][i]=a[j][k]; b[j][i]=b[(j+k+1)%n][i-k-1];
                }

    m=0;
    for(i=0;i<n;++i)
        m=max(m,f[i][n-1]);
    cout<<m<<endl;
}

