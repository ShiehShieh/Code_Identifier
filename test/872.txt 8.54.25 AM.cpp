#include <iostream>
using namespace std;
char s[2100];
int main()
{
    int a=0,b=0;
    gets(s);
    int i = strlen(s);
    a=s[i-2]-48;
    b=s[i-1];
    if ((a+b)%4==1) 
    {
       printf("1");
    }
    else
    {
       printf("0");
    }
}

