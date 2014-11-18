#include<stdio.h>
#include<math.h>
#define WEI(n,i) ((n)/TEN[(i)-1])%10;
#define maxl 100
#define maxstep 100000
long long n,num;
long long TEN[12],rec[maxstep+10];
void GetMinMax(long long *a,long long *b)
{
    long long min=0,max=0,c[maxl+10],tmp,i,j;
    for(i=1;i<=n;++i)
      c[i]=WEI(num,i);
    for(i=1;i<=n;++i)
      for(j=n;j>=i+1;--j)
        if(c[j]<c[j-1])
          tmp=c[j],c[j]=c[j-1],c[j-1]=tmp;
    for(i=1;i<=n;++i)
    {
        min+=c[i]*TEN[n-i];
        max+=c[i]*TEN[i-1];
    }
    *a=min,*b=max;
}
int main()
{
    long long i,cnt,a,b,from;

    TEN[0]=1;
    for(i=1;i<12;++i)
      TEN[i]=TEN[i-1]*10;
    while(scanf("%I64d",&num)!=EOF)
    {
    n=(long long)(log((double)num)/log(10.0))+1;
      cnt=0;
 rec[0]=num;
      do{
          GetMinMax(&a,&b);
          num=b-a;
          for(i=0;i<=cnt;++i)
          if(rec[i]==num)
          {
              from=i;
              goto out;
          }
          rec[++cnt]=num;
      }while(1);
out:
      for(i=from;i<=cnt;++i)
      {
        printf("%I64d",rec[i]);
        if(i<cnt) printf(" "); else printf("\n");
      }
    }
    return 0;
}

