#include<iostream>
using namespace std;
int main()
{
    char str[10000];
    cin>>str;
    int n,a;
    n=strlen(str);
    if(n==1)
    a=str[0]-48;
    else
    a=((str[n-1]-48)+(str[n-2]-48)*10);
    if(a%4==1||a%4==2)
    cout<<"1";
    else 
    cout<<"0";
    return 0;
}
 
