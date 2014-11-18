#include <iostream>
using namespace std;
int main(void)
{int n;
cin>>n;
int a[1001]={0};
a[1000]=1;
int bs=1000,c,d,e=0;
for(;n>4;n-=3)
{e=0;
for(c=1000;c>bs-1;c--)
a[c]*=3;
for(c=1000;c>bs-1;c--) 
if(a[c]>9)
{d=a[c]%10;
a[c-1]+=(a[c]-d)/10;
a[c]=d;
}
for(e=0;e<1000;e++)
if(!(a[e]==0))break;
bs=e;
}
for(c=1000;c>bs-1;c--)
a[c]*=n;
for(c=1000;c>bs-1;c--)
if (a[c]>9)
{d=a[c]%10;
a[c-1]+=(a[c]-d)/10;
a[c]=d;}
for(e=0;e<1000;e++)
if(!(a[e]==0))
break;
bs=e;
for(n=bs;n<1001;n++)
cout<<a[n];
return 0;
}

