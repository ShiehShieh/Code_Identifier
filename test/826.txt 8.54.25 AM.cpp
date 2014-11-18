#include<stdio.h>
#define maxn 500000
long n,k,people[maxn+10];
int main()
{
    long o,i,pos,ans,arg1,arg2;
    char mark[5];
    scanf("%ld%ld",&n,&k);
    pos=0;
    ans=0;
    for(o=1;o<=k;++o)
    {
      scanf("%s",mark);
      switch(mark[0])
      {
        case 'A':
             scanf("%ld",&arg1);
             for(i=pos+1;i<=arg1;++i)
               ans+=people[i];
             printf("%ld ",ans);
             pos=arg1;
             break;
        case 'B':
             scanf("%ld%ld",&arg1,&arg2);
             if(arg1>pos)
               people[arg1]+=arg2;
             else
               ans+=arg2;
             break;
        case 'C':
             scanf("%ld%ld",&arg1,&arg2);
             if(arg1>pos)
               people[arg1]-=arg2;
             else
               ans-=arg2;
      }
    }
    return 0;
}

