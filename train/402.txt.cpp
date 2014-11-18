/*Vijos P1469*/
#include<iostream>
#include<math.h>
using namespace std;
long a[65536],x[65536],n,i,h;
int comp(const void *a,const void *b)
{
    return (*(long*)a - *(long*)b);
}
void dfs(long x,long l,long r)
{
     a[x]=l;
     l++;
     if (l>r) return;
     dfs(x*2,(l+r)/2+1,r);
     dfs(x*2+1,l,(l+r)/2);
}
int main()
{
    cin>>n;
    h=(long)(log(n)/log(2)+1E-8)+1;
    for (i=0;i<n;i++) cin>>x[i];
    qsort(x,n,sizeof(x[0]),comp);
    dfs(1,0,n-1);
    for (i=1;i<n;i++) cout<<x[a[i]]<<" ";
    if (n!=0) cout<<x[a[n]];
    cout<<endl;
    return 0;
}

