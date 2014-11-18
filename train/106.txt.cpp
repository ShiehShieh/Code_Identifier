#include <stdio.h>

long long n,m,i,a,tree[1600000],b;

long long max(long i,long j)
{
     if (i>j) return(i);else return(j);
}

void insert(long long now,long long l,long long r)
{
     if (l==i&&i==r) {tree[now]=a;return;}
     if (i<=(l+r)/2) insert(now*2,l,(l+r)/2);
     else insert(now*2+1,(l+r)/2+1,r);
     tree[now]=max(tree[now*2],tree[now*2+1]);
}

long long find(long long now,long long l,long long r,long long i,long long j)
{
     if (l==i&&j==r) return(tree[now]);
     if (j<=(l+r)/2) return(find(now*2,l,(l+r)/2,i,j));
     else if (i>(l+r)/2) return(find(now*2+1,(l+r)/2+1,r,i,j));
     else return(max(find(now*2,l,(l+r)/2,i,(l+r)/2),find(now*2+1,(l+r)/2+1,r,(l+r)/2+1,j))); 
}

int main()
{ 
    scanf("%I64d",&n);
    for (i=1;i<=n;i++) {scanf("%I64d",&a);insert(1,1,n);}
    scanf("%I64d",&m);
    for (i=1;i<=m;i++) {scanf("%I64d%I64d",&a,&b);printf("%I64d\n",find(1,1,n,a,b));}
    return 0;
}

