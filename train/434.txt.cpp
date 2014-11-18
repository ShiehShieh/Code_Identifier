#include <iostream>
using namespace std;
const int num[]={1,1,2,6,4,4,4,8,4,6};
struct In
{
  int n[110];
}a;
int i,j,l,k;
bool ok;
char s[200];
int Div(int a,int b)
{
  b %= 4;
  a = a%10;
  while (b>0)
  {
    if ( a==2 ) a = 6;
    else if ( a==4 ) a = 2;
    else if ( a==6 ) a = 8;
    else if ( a==8 ) a = 4;
    b--;
  }
  return a;
}
int calc(In a)
{
  if ( a.n[0]==1 ) return Div(num[a.n[1]],a.n[1]/5);
  int k = a.n[1];
  for (int i=a.n[0];i>1;i--)
  {
    a.n[i-1] += (a.n[i]%5)*10;
    a.n[i] /= 5;
  }
  a.n[1] /= 5;
  while ( a.n[0]>1 && a.n[a.n[0]]==0 ) a.n[0]--;
  return Div(calc(a)*num[k]*6,a.n[2]*10+a.n[1]);
}
int main()
{
  scanf("%s",&s);
  for (i=strlen(s);i>=1;i--)
   if ( strlen(s)%i==0 )
   {
     l = strlen(s)/i;
     ok = 1;
     for (k=1;k<i;k++)
      for (j=0;j<l;j++)
       if ( s[j]!=s[j+l*k] )
        ok = 0;
     if ( ok ) break;
   }
  a.n[0] = l;
  for (i=0;i<l;i++)
   a.n[l-i] = s[i]-48;
  cout << calc(a) << endl;
  cin >> l;
  return 0;
}

