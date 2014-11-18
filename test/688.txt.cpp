#include<iostream>
using namespace std;
int main()
{
	int a=0,s=0,i,t;
	for(i=1;i<=12;i++)
	{
		s+=300;
		cin>>t;
		if(t>s)
		{
			cout<<-i<<endl;
			break;
		}
		else
		{
			s-=t;
			while(s-100>=0)
			{
				s-=100;
				a+=100;
			}
		}
	}
	if(i>12)cout<<s+a*1.2<<endl;
	return 0;
}
	
