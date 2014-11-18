#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NNN 400
int a[NNN]={0};
int k,w,p,q;

void init_1()
{
     int i;
     scanf("%d%d",&k,&w);
     q=1;
     for(i=1;i<=k;i++)
         q*=2;
     q--;
}
void form1(int *a,int n)
{
     int i;
     for(i=1;i<=n+1;i++)
     if(a[i]>9)
     {
         a[i+1]+=a[i]/10;
         a[i]=a[i]%10;
     }
}
void out_1(int *a,int n)
{
     int i,j;
     i=n;
     while(a[i]==0) i--;
     for(j=i;j>=1;j--)
         printf("%d",a[j]);
     printf("\n");
}
void mult1(int *a,int n,int k)
{
     int i;
     for(i=1;i<=n;i++)
         a[i]*=k;
     form1(a,n+5);
}
void add1(int *a,int k)
{
     a[1]+=k;
     form1(a,9);
}
void add2(int *a,int b[],int n)
{
     int i;
     for(i=1;i<=n;i++)
         a[i]+=b[i];
     form1(a,n);
}
void minus1(int *a,int k)
{
     int i,p,q;
     a[1]-=k;
     for(i=1;i<10;i++)
         if(a[i]<0)
         {
             p=-a[i];
             q=p/10+1;
             if(p%10==0) q--;
             a[i+1]-=q;
             a[i]+=q*10;
         }
}
void divid1(int *a,int n,int k)
{
     int p,i,b[NNN]; /*假定能整除 */
     for(i=1;i<=n;i++)
         b[i]=0;
     p=a[n];
     for(i=n-1;i>=1;i--)
     {
         p=p*10+a[i];
         if(p>=k)
         {b[i]=p/k; p=p%k;}
     }
     form1(b,n);
     for(i=1;i<=n;i++) a[i]=b[i];
}
void comb1(int *a,int n,int m,int k)
{
     int i;
     for(i=1;i<=n;i++) a[i]=0;
     a[1]=m;
     n=(int)log10(a[1])+1;
     form1(a,n);
     for(i=2;i<=k;i++)
     {
         mult1(a,n,m-i+1);
         n+=(int)log10(m-i+1)+1;
         divid1(a,n,i);
     }
}
void oper1()
{
     int i,n;
     a[1]=1;n=2;
     for(i=1;i<=q;i++)
     {mult1(a,n,2);n++;}
     minus1(a,1+q);
}
void oper2()
{
     int b[NNN]={0};
     int i,i2,j,n,p2,t3;
     double t1;
     p=w/k;
     for(i=2;i<=p;i++)
     {
         i2=i;
         if(i2>q/2) i2=q-i;
         t1=1;
         for(j=1;j<=i2;j++)
	         t1*=(double)(q-j+1)/j;
         n=(int)log10(t1)+10;
         comb1(b,n,q,i2);
         add2(a,b,n);
     }
     if(w==p*k) return;
     p2=w-p*k;
     t3=1;
     for(i=1;i<=p2;i++)
	     t3*=2;
     t3--;
     if(t3>q-p) t3=q-p;
     for(i=1;i<=t3;i++)
     {
         t1=1;
         for(j=1;j<=p;j++)
	         t1*=(double)(q-i-j+1)/j;
         n=(int)log10(t1)+10;
         comb1(b,n,q-i,p);
         add2(a,b,n);
     }
}
int main()
{
    init_1();
    if(w>=q*k)
	    oper1();
        else 
	    oper2();
    out_1(a,390);
}
