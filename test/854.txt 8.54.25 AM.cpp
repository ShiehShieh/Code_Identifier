#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
   int i,j;
   int b[1001],tm[1001],v[1001];
   for(int t,m;cin>>t>>m;)
   {
      for(i=1;i<=m;i++)
	  {
         //scanf("%d%d",&tm[i],&v[i]);
		  cin>>tm[i]>>v[i];
	  }
	  memset(b,0,sizeof(b));
	  for(i=1;i<=m;i++)
		  for(j=t;j>=0;j--)
			  if(j>=tm[i]&&b[j-tm[i]]+v[i]>b[j])
				  b[j]=b[j-tm[i]]+v[i];
	 cout<<b[t]<<endl;

   }

}
