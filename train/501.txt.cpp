#include<iostream>
using namespace std;
long int n,m;
long int wa[100000];
struct mm
{
      long int w;
      long int order;
      long get;
}wt[100000];
int cmp1(const void *a,const void *b)
{return *(int*)b-*(int *)a;}
int cmp2(const void*aa,const void*bb)
{
    struct mm*aaa=(mm *)aa;
    struct mm*bbb=(mm *)bb;
    return aaa->w>bbb->w?-1:1;
}
int cmp3(const void*aa,const void*bb)
{
    struct mm*aaa=(mm *)aa;
    struct mm*bbb=(mm *)bb;
    return aaa->order>bbb->order?1:-1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>wa[i];
    for(int i=1;i<=m;i++){cin>>wt[i].w;wt[i].order=i;}
    qsort(wa+1,n,sizeof(wa[0]),cmp1);
    qsort(wt+1,m,sizeof(wt[0]),cmp2);
    for(int i=1;i<=n;i++)
     wt[i%m].get+=wa[i];
    wt[m].get=wt[0].get;
    qsort(wt+1,m,sizeof(wt[0]),cmp3);
    for(int i=1;i<=m;i++)cout<<wt[i].get<<" ";
}

