#include<iostream>
using namespace std;
void print_with_dot_3(double x)
{
if(x<0)
{
cout<<'-';
x=-x;
}
cout<<int(x)<<'.'<<int(x*10)%10<<int(x*100)%10<<int((x+0.0005)*1000)%10;
}
int main()
{
char z[1000],x;
cin>>z;
int i=1,l=strlen(z);
int s=0,f=1,a[2]={},b[2]={},w=0;
z[l]='+';
for(i=0;i<=l;i++)
switch(z[i])
{
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9':
s=s*10+z[i]-'0';
break;
case '+':
b[w]+=f*s;
s=0;
f=1;
break;
case '-':
b[w]+=f*s;
s=0;
f=-1;
break;
case '=':
b[w]+=f*s;
s=0;
f=1;
w=1;
break;
default:
x=z[i];
a[w]+=f*(s==0?1:s);
s=0;
}
cout<<x<<'=';
print_with_dot_3((b[1]-b[0])/(a[0]-a[1]+.0));
cout<<endl;
return 0;
} 

