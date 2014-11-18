#include<iostream>
using namespace std;
long long n,start[50010],end[50010],ans,stack[50010],top,INF;
int qsort(long long* a,long long low,long long high)
{
    long long l=low,r=high,x=a[low];
    while (l<r)
    {
          while  (l<r&&a[r]>=x)
          --r;
          a[l]=a[r];
          while(l<r&&a[l]<=x)
          ++l;
          a[r]=a[l];
    }
    a[l]=x;
    if(low<l-1)qsort(a,low,l-1);
    if(l+1<high)qsort(a,l+1,high);
}
int main()
{
    long long i,j,up,t,o;
    cin>>n;
    for(i=1;i<=n;++i)cin>>start[i]>>end[i];
    qsort(start,1,n);
    qsort(end,1,n);
    for(INF=1,i=1;i<=11;++i)
    INF*=10;
    start[n+1]=end[n+1]=INF;
    i=j=1;
    up=n*2;
    ans=0;
    top=0;
    for(o=1;o<=up;++o)
    if  (start[i]<=end[j])
    {
        stack[++top]=start[i];
        ++i;
    }
    else
    {
        t=stack[top--];
        if(0==top) ans+=end[j]-t;
        ++j;
    }
    cout<<ans;
    return 0;
}
