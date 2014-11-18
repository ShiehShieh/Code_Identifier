#include <iostream>
using namespace std;
const int maxn=100005;
struct re
{
    int h,t,k,ans,num;
}b[maxn];
struct tr
{
    int key,pr,left,right,father,son;
}a[maxn];
    int n,m,i,j,s;
int cmp(const void *a,const void *b)
{
    struct re *c=(re*)a;
    struct re *d=(re*)b;
    return c->h-d->h;
}
int compare(const void *a,const void *b)
{
    struct re *c=(re*)a;
    struct re *d=(re*)b;
    return c->num-d->num;
}
int find(int k,int x)
{
    if (a[k].left==0&&x==1) return a[k].key;
    if (a[k].left==0) return find(a[k].right,x-1);
    if (a[a[k].left].son+1==x) return a[k].key;
    if (a[a[k].left].son+1>x) return find(a[k].left,x); else return find(a[k].right,x-a[a[k].left].son-1);
}
void left_roll(int p,int q)
{
     if (a[a[p].father].left==p) a[a[p].father].left=q;
     else a[a[p].father].right=q;
     a[q].father=a[p].father;
     if (a[q].left!=0) a[a[q].left].father=p;
     a[p].right=a[q].left;
     a[q].left=p;a[p].father=q;
     a[q].son=a[p].son;
     a[p].son=1;
     if (a[p].left!=0) a[p].son+=a[a[p].left].son;
     if (a[p].right!=0) a[p].son+=a[a[p].right].son;
}
void right_roll(int p,int q)
{
     if (a[a[p].father].left==p) a[a[p].father].left=q;
     else a[a[p].father].right=q;
     a[q].father=a[p].father;
     if (a[q].right!=0) a[a[q].right].father=p;
     a[p].left=a[q].right;
     a[q].right=p;a[p].father=q;
     a[q].son=a[p].son;
     a[p].son=1;
     if (a[p].left!=0) a[p].son+=a[a[p].left].son;
     if (a[p].right!=0) a[p].son+=a[a[p].right].son;
}
void insert(int i)
{
     int k=0;
     while (true)
     {
        a[k].son++;
        if (a[i].key<=a[k].key)
        {
            if (a[k].left==0) break;
            k=a[k].left;
        }
        else
        {
            if (a[k].right==0) break;
            k=a[k].right;
        }
     }   
     a[i].son=1;a[i].father=k;
     a[i].left=0;a[i].right=0;
     if (a[i].key<=a[k].key)
     {
         a[k].left=i;
         if (a[i].pr<a[k].pr) right_roll(k,i);
     }
     else
     {
         a[k].right=i;
         if (a[i].pr<a[k].pr) left_roll(k,i);
     }
}
void del(int k)
{
     while (a[k].left!=0||a[k].right!=0)
     {
           if (a[k].left==0) left_roll(k,a[k].right);
           else if (a[k].right==0) right_roll(k,a[k].left);
           else if (a[a[k].right].pr<=a[a[k].left].pr) left_roll(k,a[k].right);
           else right_roll(k,a[k].left);
     }
     if (a[a[k].father].left==k) a[a[k].father].left=0;else a[a[k].father].right=0;
     k=a[k].father;
     while (k!=0)
     {
           a[k].son--;
           k=a[k].father;
     }
     a[0].son--;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i].key);
        a[i].pr=rand()%100000000;
        a[i].father=0;
        a[i].left=0;
        a[i].right=0;
        a[i].son=1;
    }
    for (i=0;i<m;i++)
    {
        scanf("%d %d %d",&b[i].h,&b[i].t,&b[i].k);
        if (b[i].h>b[i].t) swap(b[i].h,b[i].t);
        b[i].num=i;
    }
    qsort(b,m,sizeof(b[0]),cmp);
    i=0;j=1;a[0].key=2100000000;a[0].pr=-100000;s=1;
    for (i=0;i<m;i++)
    {
        while (j<=b[i].t)
        {
            insert(j);
            j++;
        }
        while (s<b[i].h)
        {
            del(s);
            s++;
        }
        b[i].ans=find(0,b[i].k);
    }
    qsort(b,m,sizeof(b[0]),compare);
    for (i=0;i<m;i++)
        printf("%d",b[i].ans);
    return 0;
}

