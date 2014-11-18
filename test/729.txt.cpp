#include<cstdio>
#include<queue>
#include<fstream>
#include<climits>
using namespace std;
const int N = 101;
int s[N][N];
void pack(int p,int n,int v,int&Min,int&x)
{
   bool c[N*100] = {0};
   int sum(0);
   c[0] = true;
   for(int i=1;i<=n;++i)
      for(int j=v;j>=s[p][i];--j)
      {
        if( c[j-s[p][i]] )
        {
            c[j] = true;
            if(j>sum) sum=j;
        }
        if( c[v] ) return;
      }
   if(Min>sum) Min=sum,x=p;
   return ;
}
int main()
{
   int n,m;
   while(scanf("%d",&n)!=EOF)
   {
       int Min(INT_MAX),x;
       for(int i=1;i<=n;++i)
       {
           int j=1,sum(0);
           while(scanf("%d",&m),m!=-1)
           {
               s[i][j++] = m;
               sum += m;
           }
           s[i][0] = j-1;
           if(Min>sum) Min = sum,x = i;
       }
       int ans(0);
       for(int h=Min;h>=1;h = Min)
       {
           for(int i=1;i<=n;++i)
               if(  x!=i  )
               {
                  pack(i,s[i][0],h,Min,x);
                  if(h!=Min) break;
               }
           if(h==Min) { ans=h; break; }
       }
       printf("%d\n",ans);
   }
   return 0;
}
