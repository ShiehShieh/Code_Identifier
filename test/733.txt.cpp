#include<iostream>
#include<string>
using namespace std;

string s[101][101];
int z[101];

bool INit(string x,int w)
{
for(int i=1;i<=z[w];i++)
if(x==s[w][i])
return 1;
return 0;
}

int main()
{
memset(z,0,sizeof(z));
int a,b;
string t;
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a>>t>>b;
for(int i=1;i<=a;i++)
{
cin>>t;
for(int j=b;j<=100;j++)
if(!INit(t,j))
s[j][++z[j]]=t;
}
}
for(int i=1;i<=100;i++)
if(z[i-1]==i-1 && z[i]==i)
{
cout<<i<<" ";
for(int j=1;j<=i;j++)
if(!INit(s[i][j],i-1))
cout<<s[i][j]<<endl;
}

return 0;
}

