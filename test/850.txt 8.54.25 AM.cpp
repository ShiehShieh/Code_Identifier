#include<iostream>
#include<algorithm>
using namespace std; 
int main()
{
	int b[1000],n,i,k,x,f,y,num=1,j,u;
	memset(b,1,sizeof(b));
	scanf("%d%d%d",&n,&k,&f);
	u=n;
	for(i=0;i<n;i++)
    b[i]=1;
	for(i=0;i<f;i++)
	{
		scanf("%d%d",&x,&j);
		b[x-1]+=j;
	}
	u=0;
   for(i=0;i<n;i++)
   {
	   if(u+b[i]>k){num++;u=b[i];}
	   else u+=b[i];
   }
	printf("%d\n",num);
	return 0;
}

