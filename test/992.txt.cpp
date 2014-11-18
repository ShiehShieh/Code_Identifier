#include<iostream>
#include<cmath>
using namespace std;
int l,m,num;
bool used[20000];
struct tre
{
    int le,ri;
}are[200];
int main()
{
    cin>>l>>m;
    l++;
    for(int i=1;i<=m;i++)
    cin>>are[i].le>>are[i].ri;
    for(int i=1;i<=m;i++)
    {
       for(int j=are[i].le;j<=are[i].ri;j++)
       {
         if(used[j]==false){num++;used[j]=true;}
       }
    }
    cout<<l-num;
}

