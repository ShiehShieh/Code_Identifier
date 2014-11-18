#include <iostream>
using namespace std;

int main()
{
    int t,m,i,j,max;
    cin>>t>>m;
    int T[101],V[101],F[1001][101];
    for (i=1;i<=m;i++) cin>>T[i]>>V[i];
    for (i=0;i<=t;i++) F[i][0]=0;
    for (i=0;i<=m;i++) F[0][i]=0;
    for (i=1;i<=t;i++)
        for (j=1;j<=m;j++)
        {
            max=F[i][j-1];
            if (i>=T[j]) if (F[i-T[j]][j-1]+V[j]>max) max=F[i-T[j]][j-1]+V[j];
            F[i][j]=max;
        }
    cout<<F[t][m]<<endl;
    return 0;
}
