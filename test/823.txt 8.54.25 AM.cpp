#include<string>
#include<iostream>
using namespace std;
long k,total=0;
void ini(void)
{
cin>>k;
return;
}
void work(long n,long m)
{
if(m>k-n) return;
if(n==k) {total++;return;}
work(n,m+1);
if(m>0) work(n+1,m-1);
return;
}
int main(void)
{
ini();
work(0,0);
cout<<total;
return 0;
}

