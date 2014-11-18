#include<iostream>
#include<string>
#define Len 300
#define Len2 210
using namespace std;

bool ok;

struct BigNum
{
int x[Len+1];
BigNum operator -(BigNum u)
{
BigNum r;
for(int i=0;i<=Len;i++)
r.x[i]=x[i];
for(int i=0;i<Len;i++)
{
if(r.x[i]<u.x[i])
r.x[i+1]--,r.x[i]+=10;
r.x[i]-=u.x[i];
}
return r;
}
BigNum operator *(BigNum u)
{
BigNum r;
for(int i=0;i<=Len;i++)
r.x[i]=0;
for(int i=0;i<Len;i++)
for(int j=0;j+i<Len;j++)
r.x[i+j]+=x[i]*u.x[j];
for(int i=0;i<Len;i++)
r.x[i+1]+=r.x[i]/10,r.x[i]%=10;
return r;
}
bool operator >(BigNum u) //>=
{
for(int i=Len;i>=0;i--)
{
if(x[i]>u.x[i])
return 1;
if(x[i]<u.x[i])
return 0;
}
return 1;
}

BigNum operator /(BigNum u)
{
BigNum div[Len2+1],r,n;

for(int i=0;i<=Len;i++)
r.x[i]=0,n.x[i]=x[i];

for(int i=0;i<=Len2;i++)
{
for(int j=0;j<i;j++)
div[i].x[j]=0;
for(int j=0;j+i<Len;j++)
div[i].x[j+i]=u.x[j];
}


for(int i=Len2;i>=0;i--)
while(n>div[i])
{
r.x[i]++,n=n-div[i];
}
for(int i=0;i<Len;i++)
r.x[i+1]+=r.x[i]/10,r.x[i]%=10;
return r;
}
BigNum operator %(BigNum u)
{
BigNum div[Len2+1],r,n;
for(int i=0;i<=Len;i++)
r.x[i]=0,n.x[i]=x[i];
for(int i=0;i<=Len2;i++)
{
for(int j=0;j<i;j++)
div[i].x[j]=0;
for(int j=0;j+i<Len;j++)
div[i].x[j+i]=u.x[j];
}

for(int i=Len2;i>=0;i--)
{
while(n>div[i])
r.x[i]++,n=n-div[i];
}
return n;
}
}a,b,c;

bool Zero(BigNum u)
{
for(int i=0;i<=Len;i++)
if(u.x[i]>0)
return 0;
return 1;
}

BigNum gcd(BigNum x,BigNum y)
{
while(!(Zero(y)))
{
BigNum t=x%y;
x=y,y=t;
}
return x;
}

int main()
{
string t1,t2;
cin>>t1>>t2;
int w=-1;
for(int i=t1.length()-1;i>=0;i--)
a.x[++w]=t1[i]-'0';
w=-1;
for(int i=t2.length()-1;i>=0;i--)
b.x[++w]=t2[i]-'0';

c=gcd(a,b);
c=a/gcd(a,b);
c=c*b;

ok=0;
for(int i=Len;i>=0;i--)
{
if(i==0 || c.x[i]>0)
ok=1;
if(ok)
cout<<c.x[i];
}
cout<<endl;

return 0;
}

