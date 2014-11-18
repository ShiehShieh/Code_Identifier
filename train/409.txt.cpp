/*  Vijos P1445  */
#include <iostream>
using namespace std;

typedef struct node
{
        int d;
        int num;
}Tao;

int n,m;
int ap[100001];
Tao tt[100001];
int ans[100001];

void qksort1(int b,int e,int a[])
{
     int i,j;
     int k;
     if (b<e)
       {
             i=b;j=e;
             k=a[i];
             while (i<j)
               {
                   while (i<j && a[j]<=k) --j;
                   a[i]=a[j];
                   while (i<j && a[i]>=k) ++i;
                   a[j]=a[i];
               }
             a[i]=k;
             qksort1(b,i-1,a);
             qksort1(i+1,e,a);
       }
}

void qksort2(int b,int e,Tao a[])
{
     int i,j;
     Tao k;
     if (b<e)
       {
             i=b;j=e;
             k=a[i];
             while (i<j)
               {
                   while (i<j && a[j].d<=k.d) --j;
                   a[i]=a[j];
                   while (i<j && a[i].d>=k.d) ++i;
                   a[j]=a[i];
               }
             a[i]=k;
             qksort2(b,i-1,a);
             qksort2(i+1,e,a);
       }
}

void init()
{
     cin>>n>>m;
     for (int i=1;i<=n;i++)
        scanf("%d",&ap[i]);
     for (int i=1;i<=m;i++)
        {
           scanf("%d",&tt[i].d);
           tt[i].num=i;
        }
     qksort1(1,n,ap);
     qksort2(1,m,tt);
}

void work()
{
     int i,j;
     i=j=1;
     while (i<=n)
       {
           ans[tt[j].num]+=ap[i];
           j++;
           if (j>m)
             j=1;
           i++;
       }
}

void print()
{
     for (int i=1;i<=m;i++)
       printf("%d ",ans[i]);
     printf("\n");
}

int main(void)
{
    init();
    work();
    print();
    return 0;
}
