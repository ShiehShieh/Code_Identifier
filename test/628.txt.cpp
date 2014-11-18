#include<iostream>
using namespace std;
int main()
{int i,num,s,t1,t2,map[10][10]={0},j,k,f[10]={0},b[51]={0},l,last; 
 string a;
 cin>>a>>num;
 for(i=1;i<=num;i++)
   {cin>>t1>>t2;
    map[t1][t2]=1;
   }
 for(i=0;i<=9;i++)
   map[i][i]=1;
 for(k=0;k<=9;k++)
   for(i=0;i<=9;i++)
     for(j=0;j<=9;j++)
       if(map[i][k]&&map[k][j])
         map[i][j]=1;
 for(i=0;i<=9;i++)
   for(j=0;j<=9;j++)
      f[i]+=map[i][j];
 b[1]=1;
 l=1;
 for(i=0;i<=a.size()-1;i++)
   {last=0;
    j=1;
    while(j<=l)
      {b[j]=f[a[i]-'0']*b[j]+last;
       last=b[j]/10;
       b[j]%=10;
       if(j==l&&last!=0)
         {l++;
          b[j+1]=last;
          break;
         }
       j++;
      }
    j=l;
   } 
 j=l;
 while(j>=1)
   {cout<<b[j];
    j--;
   }
 return 0;
} 

