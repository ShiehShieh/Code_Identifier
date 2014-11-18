#include<iostream>
using namespace std;
int c[10002]={1,1},d[1302]={},x=0;
bool szs(int a)
{
    if (a<=10000)return !c[a];
    for (int i=1;d[i]*d[i]<=a;i++)
        if (a%d[i]==0)return 0;
    return 1;        
}
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n+2],b[n+2];
	for (int i=1;i<=n;i++)
	cin>>a[i];
	b[0]=b[n+1]=0;
	int z=0,s=0,f=0,t=0;
	for (int i=2;i<=97;i++)
	   if (c[i]==0)
       {
            d[++x]=i;
            for (int j=2*i;j<=10000;j+=i)
                c[j]=1;
        }
    for (int i=101;i<=10000;i++)
        if (c[i]==0)d[++x]=i;
	do 
	{
        if (++f>n||z==k)
            s-=a[f=b[z--]];
        else
        {
            s+=a[b[++z]=f];
            if (z==k&&szs(s))t++;
        }
    }while(z>=0);
	cout<<t<<endl;
	return 0;
}
