#include<stdio.h>
#include<cmath> 
int n,b[21],k;
long a[21],ans=0;
int Is(long p)
{
  long i;
  for(i=2;i<=sqrt(p);i++)
if(p%i==0)
return 0;
return 1;
}
int dfs(int t,int sum,int p)
{
int i,j;
if(p==k)
{ 
if(Is(sum))
{
ans++;
}  
return 0;
}
if(t>n)
return 0; 
dfs(t+1,sum+a[t],p+1);
dfs(t+1,sum,p);   
}
int main()
{
int i,j;
scanf("%d%d",&n,&k);
for(i=1;i<=n;i++)
scanf("%ld",&a[i]);
dfs(1,0,0);  
printf("%ld",ans);
return 0;
}

