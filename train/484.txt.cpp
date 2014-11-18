#include<iostream>
using namespace std;
struct s
{
	int x;
	int a;
	int b;
	int c;
	int tot;
}s[10001],t;
int main()
{
	int n,i,j,k;
	cin>>n;

	for(i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b>>s[i].c;
		s[i].tot=s[i].a+s[i].b+s[i].c;
		s[i].x=i;
	}
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		if(s[i].a<s[j].a)
		{
			t=s[i];
			s[i]=s[j];
			s[j]=t;
		}
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		if(s[i].tot<s[j].tot)
		{
			t=s[i];
			s[i]=s[j];
			s[j]=t;
		}
	for(i=1;i<=5;i++)cout<<s[i].x<<" "<<s[i].tot<<endl;
	return 0;
}

