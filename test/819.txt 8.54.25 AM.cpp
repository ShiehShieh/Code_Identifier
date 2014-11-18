#include<iostream>
using namespace std;
main()
{int n,m,a[10000],i,j;
 cin>>n>>m;
 int s=1;
 a[s]=1;
 for(i=2;i<=n;i++) 
    {for(j=1;j<=s;j++)
        {if((a[j]+i)%m==0)break;
        }
     if(j>s)a[++s]=i;
     }
 cout<<s;
}

