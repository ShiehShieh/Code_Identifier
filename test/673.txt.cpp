#include<iostream>
using namespace std;
void swapit(int *a,int w)
{
	int i;
	for(i=1;i<=w/2;i++)
	swap(a[i],a[w-i+1]);
	return;
}
void count(int *a,int w)
{
	int i,f,s,t;
	for(i=w-1;i>0;i--)
	if(a[i+1]>a[i])break;
	s=i+1;
	f=i;
	for(i=w;i>0;i--)
	if(a[i]>a[f])break;
	swap(a[f],a[i]);
	swapit(a+f,w-f);
	return;
}
int main()
{
	int a[10001],n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=m;i++)
	count(a,n);
	for(i=1;i<n;i++)
	cout<<a[i]<<' ';
	cout<<a[n]<<endl;
	return 0;
}
