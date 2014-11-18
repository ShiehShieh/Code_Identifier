#include<iostream>
using namespace std;
int pp(char *a,char *b)//a匹配b
{
	int la=strlen(a),lb=strlen(b),i,l;
	char c[31]={};
	if(la<lb)l=la;else l=lb;
	for(i=1;i<l;i++)
	{
		c[i-1]=b[i-1];
		if(strcmp(a+la-i,c)==0)return i;
	}
	return 0;
} 
int main()
{
    int i,n,t,max=0,a[41]={},l[41]={1},b[21]={},z=0,f=0;
    char x[21][31]={'$'};
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>x[i];
    cin>>x[0][1];
    do
    if(++f>n)
    b[f=a[z--]]--;
    else if((t=pp(x[a[z]],x[f]))>0&&b[f]<2)
    {
		a[++z]=f;
		b[f]++;
		l[z]=l[z-1]+strlen(x[f])-t;
		f=0;
		if(l[z]>max)max=l[z];
	}while(z>=0);
	cout<<max<<endl;
	return 0;
}

