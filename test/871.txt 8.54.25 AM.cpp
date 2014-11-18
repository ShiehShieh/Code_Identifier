#include <iostream>
using namespace std;
int n,a[200000],b[200000],ans;
void qsort(int l,int r)
{
     int i=l,j=r,mid=a[(l+r)/2];
     for (;i<=j;)
     {
         for (;a[i]<mid;){i++;}
         for (;a[j]>mid;){j--;}
         if (i<=j)
         {
            swap(a[i],a[j]);
            i++;
            j--;
         }       
     }
     if (i<r) qsort(i,r);
     if (j>l) qsort(l,j);
}
     
int main()
{
     scanf("%d",&n);
     for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
     qsort(1,n);
     int p1=1,w1=n,p2=1,w2=0,k;
     ans=0;
     for (int i=1;i<=n-1;i++)
     {
         k=0;
         if ((p1<=w1)&&((p2>w2)||(a[p1]<b[p2])))
         {
             k+=a[p1++];
         }
         else
         {
             k+=b[p2++];
         }
         if ((p1<=w1)&&((p2>w2)||(a[p1]<b[p2])))
         {
             k+=a[p1++];
         }
         else
         {
             k+=b[p2++];
         }
         ans+=k;
         b[++w2]=k;
     }
     printf("%d\n",ans);
}
    

