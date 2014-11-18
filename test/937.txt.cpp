#include<iostream>
using namespace std;
int np,n1,n2,t,n;
int * p_money,* p_sent;
string * p_str,str_t;
int s(string & s)
{
for(int i = 0;i < np;i++)
 if(s == p_str[i]) return i;
return -1;
}
int main()
{
cin >> np;
p_str = new string[np];
p_money = new int[np];
p_sent = new int[np];
for(int i = 0;i < np;i++)
{
 cin>>p_str[i];
 p_money[i] = 0;
}
for(int i = 0;i < np;i++)
{
 cin >> str_t;
 cin >> n1 >> n2;
 if(n2 !=0)  t = n1 / n2;
 else t= 0;
 n = s(str_t);
 p_sent[n] = t * n2;
 //p_money[n] += n1 - p_sent[n];
 for(;n2 > 0;n2--)
 {
  cin >> str_t;
  p_money[s(str_t)] += t;
 }
}
for(int i = 0;i < np;i++)
 cout<<p_str[i]<<' '<<(p_money[i] - p_sent[i])<<endl;
return 0;
} 
