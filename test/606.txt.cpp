#include <iostream>

using namespace std;

int main()
{int i,j,k,s,t,w;
cin>>s>>t>>w;
bool x=1;
string a;
cin>>a;
for(i=0;i<5;i++)
{x=0;
    for(j=w-1;j>=0;j--)
if(a[j]<'a'+t-w+j)
{a[j]=a[j]+1;
for(k=j+1;k<w;k++)
a[k]=a[k-1]+1;
x=1;
break;
}
if(x==1)
cout<<a<<endl;
else break;
}

    return 0;
}

