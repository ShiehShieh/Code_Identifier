#include <iostream>
#include <string>
#include <iomanip>

 using namespace std;

int main()
{string a;
char x;
double da,l0=0,r0=0,l=0;
bool lr=1;
int n,i;
cin>>a;
n=a.length();
for(i=0;i<n;i++)
{if(a[i]-'0'>=0&&a[i]-'0'<10)
l=l*10+(a[i]-'0');
else if(a[i]=='-')
{if(lr==1)
    l0=l+l0;
 else l0=l0-l;
l=0;lr=0;
}
else if(a[i]=='+')
{if(lr==1)
    l0=l+l0;
 else l0=l0-l;
l=0;lr=1;
}
else if(a[i]=='=')
{if(lr==1)
    l0=l+l0;
 else l0=l0-l;
    break;
}
else {x=a[i];
if(l==0)
l=1;
if(lr==1)
    r0=r0-l;
 else r0=r0+l;
 l=0;lr=1;
}
}
lr=1;
l=0;

for(i=i+1;i<n;i++)
{if(a[i]-'0'>=0&&a[i]-'0'<10)
l=l*10+(a[i]-'0');
else if(a[i]=='-')
{if(lr==1)
    l0=l0-l;
 else l0=l0+l;
l=0;lr=0;
}
else if(a[i]=='+')
{if(lr==1)
    l0=l0-l;
 else l0=l0+l;
l=0;lr=1;
}

else {x=a[i];
if(l==0)
l=1;
if(lr==1)
    r0=r0+l;
 else r0=r0-l;
 l=0;lr=1;
}
}
if(lr==1)
    l0=l0-l;
 else l0=l0+l;

da=l0/r0;
cout<<x<<"=";
cout<<setiosflags(ios::fixed)<<setprecision(3)<<da;
return 0;
}
