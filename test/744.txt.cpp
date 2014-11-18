#include <iostream>
using namespace std;
int main()
{
	int n,k,i=1,ii=i;
	cin>>k>>n;
	int a[2000]={};
	a[1]=1;
	while (i<n)
	{
		a[++i]=a[ii]*k;
		ii=i;
		for (int j=1;j<ii;j++)
			a[++i]=a[ii]+a[j];
	}
	cout<<a[n]<<endl;		
	return 0;
}

