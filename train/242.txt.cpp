#include<iostream>
using namespace std;
int f[61][3300],v[61][4],w[61][4],t[61];
int main()
{
    int m,n,i,j,a1,a2,a3;
    cin>>m>>n;
    m/=10;
    for(i=1;i<=61;i++)
    t[i]=1;
    j=1;
    for (i=1;i<=n;i++)
    {
        cin>>a1>>a2>>a3;
        if  (a3>0)
        {
            for (int k=1;k<=n;k++)
            {
                if(v[k][0]==a3)a3=k;
            }
            t[a3]++;
            v[a3][t[a3]]=a1/10;
            w[a3][t[a3]]=a2*a1;
        }
        else
        {
            v[j][0]=i;
            v[j][1]=a1/10;
            w[j++][1]=a2*a1;
        }
    }
    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
        f[i][j]=f[i-1][j];
        if(j>=v[i][1])
        f[i][j]=max(f[i][j],f[i-1][j-v[i][1]]+w[i][1]);
        if(j>=v[i][1]+v[i][2])
        f[i][j]=max(f[i][j],f[i-1][j-v[i][1]-v[i][2]]+w[i][1]+w[i][2]);
        if(j>=v[i][1]+v[i][3])
        f[i][j]=max(f[i][j],f[i-1][j-v[i][1]-v[i][3]]+w[i][1]+w[i][3]);
        if(j>=v[i][1]+v[i][2]+v[i][3])
        f[i][j]=max(f[i][j],f[i-1][j-v[i][1]-v[i][2]-v[i][3]]+w[i][1]+w[i][2]+w[i][3]);
    }
    cout<<f[n][m];
}

