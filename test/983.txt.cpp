#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[7],b[7],m[7];
int main()
{  int i,t=0,d=0;
   for (i=0;i<7;i++)
     cin >> a[i] >> b[i];
   for (i=0;i<7;i++)
    {  m[i]=a[i]+b[i];
       if (m[i]>t)
       {  t=m[i];
          d=i+1;
       }
    }
   if (t >8) cout << d;
   else cout << 0;

}

