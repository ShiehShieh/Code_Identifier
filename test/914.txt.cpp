#include <iostream>
using namespace std;
int main()
{
    char a[13],x,t;
    cin>>a;
    int s=0,j=0;
    for(int i=0;i<12;i++)
    {
            if(a[i]!='-')
            {
                         j++;
                         s+=j*(a[i]-'0');
            }
    }
    if(s%11==10) t='X';
    else t=s%11+'0';
    if(t==a[12]) cout<<"Right";
    else 
    {
         a[12]=t;
         cout<<a;
    }
    return 0;
}

