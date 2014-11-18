#include <iostream>
using namespace std;

long long a,b,ans1,ans[100001],maakk,lmm,tttmp[100001];

void search11(long long x,long long y,long long dep)
{
     long long l1,l2,i,nx,ny,j;
     l1=max(tttmp[dep-1]+1,y/x);
     l2=min(y*(lmm-dep+1)/x,ans1-1);
     for (i=l1;i<=l2;i++)
     {
         nx=x;ny=y;
         tttmp[dep]=i;
         nx=nx*i-ny;
         if (x<0)continue;
         ny=ny*i;
         if (dep<lmm)
         search11(nx,ny,dep+1);
         if ( i<ans1 && nx==0 )
         { maakk=1;ans1=i;
        for (j=1;j<=lmm;j++)
      ans[j]=tttmp[j];
         }
     }
}

void work()
{
     long long i;
     maakk=0;tttmp[0]=1;ans1=99999999;
     while(maakk==0)
     {lmm++;search11(a,b,1);
     }
     for (i=1;i<=lmm;i++)
      cout<<ans[i]<<" ";
     cout<<endl;
}

int main(void)
{
      cin>>a>>b;
      work();
      return 0;
}
