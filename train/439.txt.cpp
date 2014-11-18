#include <iostream>
#include <cmath>
using namespace std;

long long dat[800000],a[800000],n,i,m,x,y;

void bt(int k,int l,int r)
{
    if (l==r) dat[k]=a[l];
        else
        {
            bt(k*2,l,(l+r)/2);
            bt(k*2+1,(l+r)/2+1,r);
            dat[k]=max(dat[k*2],dat[k*2+1]);
        }
}

long long check(int k,int l,int r,int x,int y)
{
    if (x<=l && y>=r) return dat[k];
    if (x<=(l+r)/2 && y>(l+r)/2) return max(check(k*2,l,(l+r)/2,x,y),check(k*2+1,(l+r)/2+1,r,x,y));
    if (y<=(l+r)/2) return check(k*2,l,(l+r)/2,x,y);
    return check(k*2+1,(l+r)/2+1,r,x,y);
}

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
    bt(1,1,n);
    cin>>m;
    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        cout<<check(1,1,n,x,y);
    }
}
