#include <iostream>
using namespace std;

int main()
{
    int bx,by,cx,cy;
    cin>>bx>>by>>cx>>cy;
    int i,j,k;
    int f[17][17];
    memset(f,-1,sizeof(f));
    f[cx][cy]=f[cx-1][cy-2]=f[cx-2][cy-1]=f[cx-2][cy+1]=f[cx-1][cy+2]=0;
    f[cx+1][cy+2]=f[cx+2][cy+1]=f[cx+2][cy-1]=f[cx+1][cy-2]=0;
    if (f[0][0]!=0) f[0][0]=1;
    for (i=0;i<=bx;i++)
        for (j=0;j<=by;j++)
        {
            if (f[i][j]==0||(i==0&&j==0)) continue;
            if (j==0) f[i][j]=f[i-1][j];
            else if (i==0) f[i][j]=f[i][j-1];
            else f[i][j]=f[i-1][j]+f[i][j-1];
        }
    cout<<f[bx][by]<<endl;
    return 0;
}
