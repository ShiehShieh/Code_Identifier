#include<iostream>
using namespace std;
int n;
char a[4][10001],temp[10001],l[10001],r[10001];
void init()
{
     int i,j;
     cin>>n;
     for (i=1;i<=3;i++)
     {
         for (j=1;j<=n;j++)
          cin>>a[i][j];
     }
}
int check(char x[],char y[])
{
    int i;
    for (i=1;i<=n;i++)
     if ( x[i]!=y[i] )
      return(0);
    return(1);
}
void work()
{
     int i,j,k;
     for (i=1;i<=3;i++)
     {
         for (j=1;j<=n;j++)
          temp[j]=a[i][n-j+1];        
         for (k=0;k<=6;k++)
         {
             for (j=1;j<=n;j++)
             {
                 l[j]=temp[j]-k;
                 r[j]=temp[j]+k;
                 if ( l[j]<'a' )
                  l[j]='z'-('a'-l[j]-1);
                 if ( r[j]>'z' )
                  r[j]='a'+(r[j]-'z'-1);
             }
             if ( i==1 )
             {
                  if ( (check(l,a[2])==1&&check(r,a[3])==1)||(check(r,a[2])==1&&check(l,a[3])==1) )
                   return;
             }
             if ( i==2 )
             {
                  if ( (check(l,a[1])==1&&check(r,a[3])==1)||(check(r,a[1])==1&&check(l,a[3])==1) )
                   return;
             }
             if ( i==3 )
             {
                  if ( (check(l,a[1])==1&&check(r,a[2])==1)||(check(r,a[1])==1&&check(l,a[2])==1) )
                   return;
             }
         }
     }
     
}
void type()
{
     int i;
     for (i=1;i<=n;i++)
      cout<<temp[i];
}
main()
{
      init();
      work();
      type();
}
