#include <iostream>
using namespace std;
int main()
{
	int n,s=0,i=0;
	cin>>n;
	while (s<n)
	{
		i++;
		s+=i;
	}
	if(i%2==1)
		cout<<s-n+1<<"/"<<i-(s-n)<<endl;
	else
		cout<<i-(s-n)<<"/"<<s-n+1<<endl;
	return 0;
}

