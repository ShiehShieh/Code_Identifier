#include<iostream>
#include<string>
#include<cmath>
using namespace std;
long int d=0;
struct tt
{ long int weight;
 long int aweight;
 long int num;
}t[500000];
int cmp1(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int cmp2(const void *a,const void *b)
{
    struct tt*aa=(struct tt*)a;
    struct tt*bb=(struct tt*)b;
    return aa->weight-bb->weight;  
}

 int m,n,apple[500000];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>apple[i];
    for(int i=1;i<=m;i++)
    {
             cin>>t[i].weight;
             t[i].num=i;
    }
    qsort(apple+1,n,sizeof(apple[1]),cmp1);
    qsort(t+1,m,sizeof(t[1]),cmp2);
  int k=m,v=n;
  while(v>=1)
 {
         t[k].aweight+=apple[v]; 
         k--;
         v--;
         if(k==0)k=m;
 }
 for(int i=1;i<=m;i++)
 {       
         for(int j=1;j<=m;j++)
         {
                 if(t[j].num==i)
                 {
                                printf("%d ",t[j].aweight);
                 }
         }
 }
}

