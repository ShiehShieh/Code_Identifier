#include <iostream>
using namespace std;
int main()
{
	int a,b,m=0,u=0;
	for (int i=1;i<=7;i++)
	{
		cin>>a;
		cin>>b;
		if (a+b-8>0&&a+b>m)
		{
			m=a+b;
			u=i;
		}
	}
	cout<<u<<endl;
	return 0;
}

