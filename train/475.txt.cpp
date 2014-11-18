#include <cstdio>
const int maxn=1500;
     int n,m,i;
     int lowbit[maxn];
     int s[maxn][maxn];
void change()
{
     int i,j,k;
     scanf("%d %d %d",&i,&j,&k);
     i++;j++;
     int tmp=j;
     while (i<=n)
     {
           j=tmp;
           while (j<=n)
           {
                 s[i][j]+=k;
                 j+=lowbit[j];
           }
           i+=lowbit[i];
     }
}
int sum(int i,int j)
{
    int tmp=j,ans=0;
    while (i>0)
    {
          j=tmp;
          while (j>0)
          {
                ans+=s[i][j];
                j-=lowbit[j];
          }
          i-=lowbit[i];
    }
    return ans;
}
void cal()
{
     int a,b,c,d,s1,s2,s3,s4;
     scanf("%d %d %d %d",&a,&b,&c,&d);
     c++;d++;
     s1=sum(c,d);s2=sum(a,b);s3=sum(c,b);s4=sum(a,d);
     printf("%d\n",s1+s2-s3-s4);
}
int main()
{
    scanf("%d",&n);n++;
    for (i=1;i<=n;i++)
        lowbit[i]=i&((i-1)^i);
    while (true)
    {
          scanf("%d",&m);
          if (m==3) break;
          if (m==1) change();
          if (m==2) cal();
    }
    return 0;
}

