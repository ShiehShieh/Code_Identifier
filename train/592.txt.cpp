#include <iostream>

using namespace std;
int jue(int i)
{if (i>0)
return i;
else return 0-i;
}
short a[20][20],m0,n0;
short x[400],y[400];
int main()
{int i,j,m,n,k,time,ke=0,zong=0;
int w=0;
cin>>m>>n>>time;
for(i=0;i<m;i++)
for(j=0;j<n;j++)
{cin>>a[i][j];
if(a[i][j]!=0)
{x[w]=i;y[w]=j;w++;}
}
for(i=0;i<w;i++)
for(j=i+1;j<w;j++)
{if (a[x[i]][y[i]]<a[x[j]][y[j]])
{k=x[i];x[i]=x[j];x[j]=k;
k=y[i];y[i]=y[j];y[j]=k;
}}
m0=-1;
n0=y[0];

while (time>0&&ke<w)
{time=time-(1+jue(x[ke]-m0)+jue(y[ke]-n0));
    if(time-x[ke]-1>=0)
{zong=zong+a[x[ke]][y[ke]];
m0=x[ke];n0=y[ke];
ke++;
}
else break;
}
cout<<zong;
    return 0;
}

