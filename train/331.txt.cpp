#include <iostream>
using namespace std;
//ifstream fin("P1409.in");
//ofstream fout("P1409.out");
int m[201];
int main()
{
 int n,w,h,l,g,i,x;
 cin>>w>>n;
 memset(m,0,sizeof(m));
 for(i=1;i<=n;i++)
    {
    cin>>x;
    m[x]++;
    }
 h=w;
 l=1;
 g=0;
 while(n>0)
    {
    while(m[h]==0)
       h--;
    while(m[l]==0)
       l++;
    if(h+l<=w)
       {
       n-=2;
       m[l]--;
       }
    else
       n--;
    m[h]--;
    g++;
   }//return 0;
 cout<<g;
 return 0;
}

