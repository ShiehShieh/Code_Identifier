#include<iostream>
using namespace std;
int k,c[101],year,m,n,len;
struct node
{
       int s,f,pay;
}p[20001];
int date[401][20001],money[401][20001],sum[401];
int num[13],dp[401][101];
int suan(int month,int day)
{
    return(num[month-1]+day); 
}
void init()
{
     int i,month1,month2,day1,day2;
     char a;
     string s;
     cin>>k>>m>>year>>n;
     num[1]=31;num[2]=28;num[3]=31;
     num[4]=30;num[5]=31;num[6]=30;
     num[7]=31;num[8]=31;num[9]=30;
     num[10]=31;num[11]=30;num[12]=31;
     len=365;
     if ( (year%4==0&&year%100!=0)||(year%100==0&&year%400==0) )
     {
          len++;
          num[2]++;
     }
     for (i=1;i<=12;i++)
      num[i]+=num[i-1];
     for (i=1;i<=n;i++)
     {
         cin>>month1>>a>>day1;
         cin>>s;
         cin>>month2>>a>>day2;
         p[i].s=suan(month1,day1);
         p[i].f=suan(month2,day2);
         cin>>p[i].pay;
     }
     for (i=1;i<=m;i++)
      cin>>c[i];
     for (i=1;i<=n;i++)
      p[i].pay=c[p[i].pay]*(p[i].f-p[i].s);
}
void ready()
{
     int i;
     for (i=1;i<=n;i++)
     {
         sum[p[i].f]++;
         date[p[i].f][sum[p[i].f]]=p[i].s;
         money[p[i].f][sum[p[i].f]]=p[i].pay;
     }
}
void Insert(int a[],int b[],int t)
{
     int c[201],la,lb,lc,i;
     la=lb=1;lc=0;
     while ( (la<=a[0]||lb<=b[0])&&lc<=k+1 )
     {
           if (  la<=a[0] && lb>b[0] )
           {
                 if (  a[la]!=c[lc] )
                 {
                       lc++;
                       c[lc]=a[la];
                 }
                 la++;
           }
           else
           {
               if ( la>a[0] && lb<=b[0] )
               {
                    if (  b[lb]+t!=c[lc] )
                    {
                          lc++;
                          c[lc]=b[lb]+t;
                    }
                    lb++;
               }
               else
               {
                   if (  a[la]>b[lb]+t )
                   {
                         if (  a[la]!=c[lc] )
                         {
                               lc++;
                               c[lc]=a[la];
                         }
                         la++;
                   }
                   else
                   {
                       if (  b[lb]+t!=c[lc] )
                       {
                             lc++;
                             c[lc]=b[lb]+t;
                       }
                       lb++;
                   }
               }
           }
     }
     c[0]=min(lc,k);
     for (i=0;i<=k;i++)
      a[i]=c[i];
}
void work()
{
     int i,j;
     dp[0][0]=1;
     for (i=1;i<=len;i++)
     {
         for (j=0;j<=dp[i-1][0];j++) 
          dp[i][j]=dp[i-1][j];
         for (j=1;j<=sum[i];j++)
          Insert(dp[i],dp[date[i][j]],money[i][j]);
     }
     if ( dp[len][0]>=k )
      cout<<dp[len][k]<<endl;
     else
      cout<<-1;
}
main()
{
      init();
      ready();
      work();
}

