#include<iostream>
#include<string>
using namespace std;
const int zs[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
string s;
short i,f=0,maxx=0,minn=32767,a[27],n;
int main()
{
	cin>>s;
	for(i=1;i<=26;i++) a[i]=0;
	for(i=0;i<=s.length()-1;i++) 
	{
		a[s[i]-'a'+1]++;
		if(a[s[i]-'a'+1]>maxx) maxx=a[s[i]-'a'+1];
	}
	for(i=1;i<=26;i++) if(minn>a[i] && a[i]!=0) minn=a[i];
	n=maxx-minn;
	for(i=0;i<=24;i++) if(n==zs[i]) f=1;
	if(f==1) cout<<"Lucky Word"<<endl<<n<<endl;
	else cout<<"No Answer"<<endl<<"0"<<endl;
	cin>>i;
	return 0;
}
