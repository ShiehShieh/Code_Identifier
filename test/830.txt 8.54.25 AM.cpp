#include <iostream>
#define Maxn 201
#define Maxk 41
#define Maxs 7
using namespace std;
int p,k,w;
string str,word[Maxs];
int f[Maxn][Maxk],num[Maxn][Maxn];
void init()
{int i;
 string s;
 cin>>p>>k;
 str="";
 for (i=1;i<=p;i++)
   {cin>>s;
    str=str+s;
   }
 cin>>w;
 for (i=1;i<=w;i++)
   cin>>word[i];
}
int work(string s)
{int i,j,m,tot;
 bool used[Maxn];
 tot=0;
 memset(used,false,sizeof(used));
 for (i=1;i<=w;i++)
   {m=0;
    j=s.find(word[i],m);
    while (m<=j)
      {if (!used[j]) 
         {tot++;
          used[j]=true;
         }
       m=j+1;
       j=s.find(word[i],m);
      }
   }
 return tot;
}
void solve()
{int i,j,u,tem;
 string s;
 memset(f,0,sizeof(f)); 
 for (i=0;i<20*p;i++)
   for (j=i;j<20*p;j++)
     {s=str.substr(i,j-i+1);
      num[i][j]=work(s);
     }
 for (i=0;i<20*p;i++)
   for (j=1;j<=k;j++)
     for (u=j-1;u<i;u++)
       {tem=f[u-1][j-1]+num[u][i];
        if (tem>f[i][j])
          f[i][j]=tem;
       }
 cout<<f[20*p-1][k];
}
int main()
{init();
 solve();
 return 0;
}
