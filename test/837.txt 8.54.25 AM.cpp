#include <iostream> 
using namespace std;
#include <string.h>
int a[10001] = {0}, b[10001] = {0}, c[100000000] = {0}; 
int main() 
{ 
int i, j, ka, kb, k,m; 
char a1[10001], b1[10001]; 
cin>>m>>a1>>b1;;
ka = strlen(a1);   
kb = strlen(b1); 

int s1,s2;
s1=s2=0;j=0;
for(i = 0; i < ka;i++) 
   {if(a1[ka-i-1]=='0'&&ka-i-1==0)continue; 
    if(a1[ka-i-1]=='.'){s1=i;continue;}
    if(a1[ka-i-1]<='9')
    a[j] = a1[ka-i-1] - '0'; 
    else a[j] = a1[ka-i-1] - 'A'+10;
    j++;
   }
ka=j;j=0;
for(i = 0; i < kb; i++) 
   {if(b1[kb-i-1]=='0'&&kb-i-1==0)continue; 
    if(b1[kb-i-1]=='.'){s2=i;continue;}
    if(b1[kb-i-1]<='9')
    b[j] = b1[kb-i-1] - '0'; 
    else b[j] = b1[kb-i-1] - 'A'+10;
    j++;
}
kb=j;
for(i = 0; i < ka; i++) 
    for(j = 0; j < kb; j++) 
    { 
      c[i + j] = c[i + j] + a[i] * b[j]; 
      c[i + j +1] = c[i + j +1] + c[i + j]/m; 
      c[i + j] = c[i + j] % m; 
    } 
    k = ka + kb; 
while(c[k-1]==0) k--;
if(s1+s2>=k)
  {cout<<"0.";
   for(i=1;i<=s1+s2-k;i++)cout<<'0';
   int q=0;
   while(c[q]==0) q++;
   for(i = k-1; i >= q; i--) 
      {
       if(c[i]>=10)cout<<char('A'+c[i]-10);
       else cout<<c[i];
      }
   return 0;
   }
for(i = k-1; i >= s1+s2; i--) 
  {
   if(c[i]>=10)cout<<char('A'+c[i]-10);
   else cout<<c[i];
  }
if(s1+s2!=0&&s1+s2<k)
  {int q=0;
   while(c[q]==0) q++;
  if(q>i){return 0;}
   cout<<'.'; 
   for(; i >= q; i--) 
   {
    if(c[i]>=10)cout<<char('A'+c[i]-10);
    else cout<<c[i];
   }
  }
}
