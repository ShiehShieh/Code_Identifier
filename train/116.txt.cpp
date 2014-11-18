#include<iostream>
using namespace std;
int calcbuy(int a1,int a2,int b1,int b2,int c)
{
	return a2-(a2-b2)/(b1-a1)*(c-a1);
}
int calclr(int dj,int cb,int bt,int xl)
{
	return (dj-cb+bt)*xl;
}
int main()
{
	int p,buy0,buy1,buy2,lr0,lr1,lr2,a,b,la=999999,lb=999999,cb,min=999999,i,n;
	bool first=true;
	cin>>p;
	do
	{
		cin>>a>>b;
		if(a==-1&&b==-1)break;
		if(first)cb=a;
		first=false;
		if(a==p-1)buy0=b;
		else if(a==p)buy1=b;
		else if(a==p+1)buy2=b;
		else
		{
			if(la<p-1&&a>p-1)buy0=calcbuy(la,lb,a,b,p-1);
			if(la<p&&a>p)buy1=calcbuy(la,lb,a,b,p);
			if(la<p+1&&a>p+1)buy2=calcbuy(la,lb,a,b,p+1);
		}	
		la=a;
		lb=b;
	}while(true);
	cin>>n;
	if(p-1>la)buy0=lb-n*(p-1-la);
	if(p>la)buy1=lb-n*(p-la);
	if(p+1>la)buy2=lb-n*(p+1-la);
	for(i=-p;i<=p;i++)
	{
		lr0=calclr(p-1,cb,i,buy0);
		lr1=calclr(p,cb,i,buy1);
		lr2=calclr(p+1,cb,i,buy2);
		if(lr1>=lr0&&lr1>=lr2&&abs(i)<abs(min))min=i;
		//if(i==-20)cout<<lr0<<' '<<lr1<<' '<<lr2<<' '<<min;
	}
	cout<<min<<endl;
	/*if((lr0=calclr(p-1,cb,buy0))>max)max=lr0;
	if(lr0<min)min=lr0;
	if((lr1=calclr(p,cb,buy1))>max)max=lr1;
	if(lr1<min)min=lr1;
	if((lr2=calclr(p+1,cb,buy2))>max)max=lr2;
	if(lr2<min)min=lr2;
	a=(max-lr1)/buy1;
	b=(min+lr1)/buy1;
	cout<<a<<' '<<b<<endl;//if(abs(a)>abs(b))cout<<a<<endl;else cout<<b<<endl;*/
	return 0;
}

