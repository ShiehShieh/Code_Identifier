#include <iostream>
#include <string.h>
using namespace std;
int np;
char name[10][255];
int find(char st[255])
{
int i;
for(i=1;i<=np;i++)
if(strcmp(st,name[i])==0) return(i);
}
int main()
{   
int i,j,m,n,p,money[10];
char st[255];
cin>>np;
for(i=1;i<=np;i++)
{cin>>name[i];money[i]=0;}
for(j=1;j<=np;j++)
{
cin>>st;
cin>>m>>n;
p=find(st);
if(n>0)
{
money[p]-=m/n*n;
for(i=1;i<=n;i++)
{
cin>>st;
money[find(st)]+=m/n;
}
} 
}
for(i=1;i<=np;i++)
cout<<name[i]<<' '<<money[i]<<'\n';
} 

