#include<iostream>
using namespace std;
int main()
{
    int m,n,k,l,d;
    cin>>m>>n>>k>>l>>d;
    int s[1001]={};
    int h[1001]={},x[1001]={};
    for (int i=1;i<=d;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a-c==1)h[c]++;
        if (c-a==1)h[a]++;
        if (b-d==1)x[d]++;
        if (d-b==1)x[b]++;
    }
    for (int i=1;i<=k;i++)
    {
    int v=-1,w=0;
    for (int j=1;j<=m;j++)
    if(v<h[j])
    {
    v=h[j];
    w=j;
    }
    h[w]=-1;
    }
    for (int i=1;i<=l;i++)
    {
    int v=-1,w=0;
    for (int j=1;j<=n;j++)
    if(v<x[j])
    {
    v=x[j];
    w=j;
    }
    x[w]=-1;
    }   
    for (int i=1;i<=m;i++)
    if (h[i]==-1)
    {
        k--;
        cout<<i;
        if (k!=0)cout<<" ";
    }
    cout<<endl;
    for (int i=1;i<=n;i++)
    if (x[i]==-1)
    {
        l--;
        cout<<i;
        if (l!=0)cout<<" ";
    }
    cout<<endl;
    return 0;
}

