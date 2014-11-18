#include <iostream>
using namespace std;
long long arr[50][50];
long long a,b,c,d,e,f,g,h,i,j;
long long a1,a2,a3,a4,a5,a6,a7,a8,a9;
int main(void)
{for(i=1;i<=3;i++)
for(j=1;j<=3;j++)
cin>>arr[i][j];
for(a=0;a<=3;a++)
for(b=0;b<=3;b++)
for(c=0;c<=3;c++)
for(d=0;d<=3;d++)
for(e=0;e<=3;e++)
for(f=0;f<=3;f++)
for(g=0;g<=3;g++)
for(h=0;h<=3;h++)
for(i=0;i<=3;i++)
{a1=(arr[1][1]+a+b+d)%4;
a2=(arr[1][2]+a+b+c+e)%4;
a3=(arr[1][3]+b+c+f)%4;
a4=(arr[2][1]+a+d+e+g)%4;
a5=(arr[2][2]+a+c+e+g+i)%4;
a6=(arr[2][3]+c+e+f+i)%4;
a7=(arr[3][1]+d+g+h)%4;
a8=(arr[3][2]+e+g+h+i)%4;
a9=(arr[3][3]+f+h+i)%4;
if(a==1) 
{a=1;
}
if((a1==0)&&(a2==0)&&(a3==0)&&(a4==0)&&(a5==0)&&(a6==0)&&(a7==0)&&(a8==0)&&(a9==0))
{for(j=0;j<a;j++)
cout<<1<<" ";
for(j=0;j<b;j++)
cout<<2<<" ";
for(j=0;j<c;j++)
cout<<3<<" ";
for(j=0;j<d;j++)
cout<<4<<" ";
for(j=0;j<e;j++)
cout<<5<<" ";
for(j=0;j<f;j++)
cout<<6<<" ";
for(j=0;j<g;j++)
cout<<7<<" ";
for(j=0;j<h;j++)
cout<<8<<" ";
for(j=0;j<i;j++)
cout<<9<<" ";
cout<<endl;
return 0;
}
}
return 0;
}

