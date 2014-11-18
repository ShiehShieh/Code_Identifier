#include<iostream>
using namespace std;
int main()
{
int i,j,k,x[20001]={0};
cin>>k;
for(i=1;i<=20000;i++)
for(j=1;j<=20000/i;j++)
x[i*j]++;
for(i=1;i<=20000;i++)
if(x[i]==k)
{  
cout<<i;
return 0;
}
cout<<"NO SOLUTION";
return 0;
}

