#include<iostream>
using namespace std;
int main()
{
	char cc[21];
	int a=0,b=0,c=0,d=0,x[6000],y[6000],e[6000],f[6000],w=0,s=0;
	while (cin>>cc)
	{
		int i;
		for (i=0;i<strlen(cc);i++)
		{
			if (cc[i]=='W'){a++;c++;}
			if (cc[i]=='L'){b++;d++;}
			if (cc[i]=='E')break;
			if ((a>=11&&a-b>=2)||(b>=11&&b-a>=2))
			{
				w++;
				x[w]=a;
				y[w]=b;
				a=0;
				b=0;
			}
			if ((c>=21&&c-d>=2)||(d>=21&&d-c>=2))
			{
				s++;
				e[s]=c;
				f[s]=d;
				c=0;
				d=0;
			}
		}
		if (cc[i]=='E')break;
	}
	for (int i=1;i<=w;i++)
	cout<<x[i]<<":"<<y[i]<<endl;
	cout<<a<<":"<<b<<endl<<endl;
	for (int i=1;i<=s;i++)
	cout<<e[i]<<":"<<f[i]<<endl;
	cout<<c<<":"<<d<<endl<<endl;
	return 0;
} 

