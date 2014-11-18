#include<iostream>
#include<cmath> 
using namespace std;
int s=0,n,a[21],k;
int p(int x)
{int i;
 if(x<2)
   return 0;
 else
   {for(i=2;i<=sqrt(x);i++)
      if(x%i==0)
         return 0;
    return 1;
   }
}  
void dfs(int x,int c,int h)
{if(c==k)
   {if(p(h))
      s++;
    return;
   }
 if(n-x+1<k-c)
   return;
 dfs(x+1,c+1,h+a[x]);
 dfs(x+1,c,h);
} 
int main()
{int i;
 cin>>n>>k;
 for(i=1;i<=n;i++)
   cin>>a[i];
 dfs(1,0,0);
 cout<<s<<endl;
 return 0;
} 
 

