#include<iostream>
#include<math.h>
using namespace std;

double x[101][101];
double r[101];
int n;

double abs(double u)
{
return u>0?u:-u;
}

void Step1(int w)
{
double maxs=-1;
int z;
for(int i=w;i<=n;i++)
if(abs(x[i][w])>maxs)
maxs=abs(x[i][w]),z=i;
for(int i=0;i<=n;i++)
swap(x[w][i],x[z][i]);
for(int i=w+1;i<=n;i++)
{
double k=x[i][w]/x[w][w];
for(int j=0;j<=n;j++)
x[i][j]-=k*x[w][j];
}
}

void Step2(int w)
{
r[w]=x[w][0]/x[w][w];
for(int i=1;i<w;i++)
x[i][0]-=r[w]*x[i][w],x[i][w]=0;
}

int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
cin>>x[i][j];
cin>>x[i][0];
}
for(int i=1;i<n;i++)
Step1(i);
for(int i=n;i>=1;i--)
Step2(i);

for(int i=1;i<=n;i++)
{
cout<<floor(r[i]+0.5);
//cout<<r[i];
if(i<n)
cout<<" ";
else
cout<<endl;
}

return 0;
}

