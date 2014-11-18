#include <iostream>
#include <string> 
using namespace std;
const char str[8]={'S','B','Q','W','S','B','Q','Y'};
int main()
{   string a,b,temp;
    bool d=false;
    cin>>temp;
    if(temp.find(".")!=string::npos)
      {a=temp.substr(0,temp.find("."));
       b=temp.substr(temp.find(".")+1,temp.size());
       d=true;
      }
    else a=temp;
    if(a[0]=='-')
      {cout<<"F";
       a=a.substr(1,a.size());
      }
    if(a[0]=='+')a=a.substr(1,a.size());
    while(a[0]=='0')a=a.substr(1,a.size());
    for(int i=a.size()-1,j=0;i>0;i--,j++)
       a=a.substr(0,i)+str[j]+a.substr(i,a.size()-1);
    for(int i=1;i<a.size();i++)
       if((a[i]>='A'&&a[i]<='Z')&&a[i-1]=='0'&&i>=2)
         a=a.substr(0,i)+a.substr(i+1,a.size());
    for(int i=1;i<a.size();)
       if(a[i-1]=='0'&&a[i]=='0')a=a.substr(0,i-1)+a.substr(i,a.size());
       else                      i++;
    while(a[a.size()-1]=='0')a=a.substr(0,a.size()-1);
    if(a=="")a="0";
    cout<<a;
    if(d==true&&b!="")cout<<"D"<<b;
    cin>>temp;
}
