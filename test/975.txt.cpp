#include<cstdio>
#include<iostream>
using namespace std;
int a[10010],b[10000];
int kuaipai1(int p,int q)
{int t,y,mid,mix1;
  t=p;
  y=q;
  mid=a[(p+q)/2];
  while (t<=y)
  {while (a[t]<mid) {t++;}
   while (a[y]>mid) {y--;}
   if (t<=y) 
     {mix1=a[t];
      a[t]=a[y];
      a[y]=mix1;      
      t++; y--;}        
   }
   if (t<q) kuaipai1(t,q);
   if (y>p) kuaipai1(p,y);
   return 0;     
}
int main()
{   int n,tol,ii,jj,j,flag,max1,i;
    scanf("%d",&n);
    for ( i=1;i<=n;i++)
      scanf("%d",&a[i]);
    kuaipai1(1,n);
    a[n+1]=300000000;    
    b[1]=a[1]+a[2];
    ii=3;    
    jj=1;
    j=1;
    tol=b[1];
    for ( i=2;i<=n-1;i++)
    { max1=200000000;
      if(a[ii]+b[jj]<max1) {max1=a[ii]+b[jj]; flag=1;}  
      if((jj+1<=j)&&(b[jj]+b[jj+1]<max1)) {max1=b[jj]+b[jj+1]; flag=2;} 
      if(a[ii]+a[ii+1]<max1) {max1=a[ii]+a[ii+1]; flag=3;} 
      tol=tol+max1;
      j++;
      b[j]=max1;
      switch (flag){
             case 1:jj++; ii++; break;
             case 2:jj=jj+2; break;
             case 3:ii=ii+2; break;
             }
     
        }
    printf("%d",tol);scanf("%d",&a[0]);
    return 0;}

