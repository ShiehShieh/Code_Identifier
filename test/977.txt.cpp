
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int x[100],y[100],z[100],m[100],n,i;
char a[100],b[100];
char name[100][21],get[100][21];


int main()
{  cin >> n;
   for (i=0;i<n;i++)
    {
     cin>>name[i];
     cin >> x[i] >> y[i];
     cin>>a[i];
     cin>>b[i];
     cin>>z[i];
    }
   for (i=0;i<n;i++)
    { m[i]=0;
      if ((x[i]>80) && (z[i]>=1)) m[i]+=8000;
      if ((x[i]>85) && (y[i]>80)) m[i]+=4000;
      if (x[i]>90)  m[i]+=2000;
      if ((x[i]>85) &&(b[i]=='Y')) m[i]+=1000;
      if ((y[i]>80) && (a[i]=='Y')) m[i]+=850;
     }
   int t=0;
   for (i=0;i<n;i++)
     if (m[i]>t)
       {  t=m[i];
          strcpy(get[0],name[i]);
       }
   cout << get[0] <<endl;
   cout << t << endl;
   long total=0;
   for (i=0;i<n;i++)
     total+=m[i];
   cout << total << endl;
}

