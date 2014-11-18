#include <iostream>
using namespace std;
const int maxn=2000001;
struct tr
{
    int l,r,sum,max;
}tree[maxn];
    int i,n,m,k,h,t;
    int a[maxn],w[maxn];
void change(int k)
{
     tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
     tree[k].l=max(tree[k*2].l,tree[k*2].sum+tree[k*2+1].l);
     tree[k].r=max(tree[k*2+1].r,tree[k*2+1].sum+tree[k*2].r);
     tree[k].max=max(tree[k*2].max,tree[k*2+1].max);
     tree[k].max=max(tree[k].max,tree[k*2].r+tree[k*2+1].l);
}
void maketree(int k,int l,int r)
{
     if (l>r) return;
     if (l==r)
     {
         tree[k].l=a[l];tree[k].r=a[l];
         tree[k].sum=a[l];tree[k].max=a[l];
         w[l]=k;
         return;
     }
     int m=(l+r)/2;
     maketree(k*2,l,m);maketree(k*2+1,m+1,r);
     change(k);
}
struct tr find(int k,int l,int r,int h,int t)
{
     if (l>r) return tree[maxn-1];
     if (l==h&&r==t)
         return tree[k];
     int mid=(l+r)/2;
     if (t<=mid) return find(k*2,l,mid,h,t);
     if (h>=mid+1) return find(k*2+1,mid+1,r,h,t);
     struct tr ans,left,right;
     left=find(k*2,l,mid,h,mid);right=find(k*2+1,mid+1,r,mid+1,t);
     ans.sum=left.sum+right.sum;
     ans.l=max(left.l,left.sum+right.l);
     ans.r=max(right.r,right.sum+left.r);
     ans.max=max(left.max,right.max);
     ans.max=max(ans.max,left.r+right.l);
     return ans;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(tree,128,sizeof(tree));
    maketree(1,1,n);
    for (i=1;i<=m;i++)
    {
        scanf("%d %d %d",&k,&h,&t);
        if (k==2)
        {
            tree[w[h]].sum=t;tree[w[h]].max=t;
            tree[w[h]].l=t;tree[w[h]].r=t;
            h=w[h];
            while (h>=2)
            {
                  h/=2;
                  change(h);
            }
        }
        else
        {
            if (h>t) swap(h,t);
            printf("%d",find(1,1,n,h,t).max);
        }
    }
    return 0;
}
