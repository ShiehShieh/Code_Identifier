#include<iostream>
using namespace std;
int n,a[101],sum=0,i,num=0,b[110];
void yi(int x)
{
    int j=x+1,y;
	b[x]=sum-a[x];
	while(b[j-1]>0)
	{
       b[j]=b[j-1]+sum-a[j++];
	}
    if(j==1){a[j]=a[j]-b[j-1];return;}
	for(y=j-2;y>x;y--)
	{a[y]+=b[y];num++;a[y+1]=a[y+1]-b[y];b[y+1]=0;}
    a[y+1]=a[y+1]-b[y];num++;
}
int main()
{
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sum=sum/n;
	memset(b,0,sizeof(b));
	for(i=0;i<n-1;i++)
	{
        if(a[i]<sum)
			yi(i);
		else if(a[i]>sum){num++;a[i+1]+=a[i]-sum;}
	}
	printf("%d\n",num);
	return 0;
}
