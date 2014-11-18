#include<iostream>
using namespace std;
unsigned long a[30000];
int la,mi;
long aa;
main()
{
char c;
while (true)
{
char c;
int pos=6,j=6;
aa=0;
for (int i=1;i<=6;i++)
{
if (!(cin>>c)) return 0;
if (c=='.'){pos=i;continue;}
j--;
a[j]=int(c)-int('0');aa=aa*10+a[j];
}
la=0;
for (int i=1;i<=6-pos;i++)
{
if (a[i]!=0) break;
la++;
aa/=10;
}
for (int i=1;i<=5-la;i++) a[i]=a[i+la];
la=5-la;
cin>>mi;pos=(la+1-pos)*mi;
unsigned long long t=0;
for (int i=1;i<=mi-1;i++)
{
for (j=1;j<=la;j++)
{
a[j]=a[j]*aa+t;
t=a[j]/10;
a[j]%=10;
}
while (t>0)
{
la++;
a[la]=t%10;
t/=10;
}
}
if (pos!=0)
{if (pos>la)
{
cout<<'.';
for (int i=1;i<=pos-la;i++) cout<<'0';
} else
{
 for (int i=la;i>pos;i--) cout<<a[i];
 cout<<'.';la=pos;
}}
for (int i=la;i>0;i--) cout<<a[i];
cout<<endl;
}
}
