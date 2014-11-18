#include <iostream>
#include <string.h>
using namespace std;
const char t[]="SBQWSBQY";
string temp,s1,s2;
int main()
{
    cin>>temp;
    s1="",s2="";
    bool can=false;
    if(temp.find(".")!=string::npos){
        s1+=temp.substr(0,temp.find("."));
        s2+=temp.substr(temp.find(".")+1,temp.size());
        can=true;
    }
    else s1+=temp;
    if(s1[0]=='-'||s1[0]=='+'){ 
        if(s1[0]=='-') cout<<"F";
        s1=s1.substr(1,s1.size());
    }
    while(s1[0]=='0') s1=s1.substr(1,s1.size());
    int i,j;
    for(i=s1.size()-1,j=0;i>0;i--,j++)
        s1=s1.substr(0,i)+t[j]+s1.substr(i,s1.size());
    for(i=1;i<s1.size();i++){
        if(s1[i]<='Z'&&s1[i]>='A'&&i>=2&&s1[i-1]=='0')
            s1=s1.substr(0,i)+s1.substr(i+1,s1.size());
    }
    for(i=1;i<s1.size();){
        if(s1[i]=='0'&&s1[i-1]=='0')
            s1=s1.substr(0,i-1)+s1.substr(i,s1.size());
        else i++;
    }
    while(s1[s1.size()-1]=='0') s1=s1.substr(0,s1.size()-1);
    if(s1=="") cout<<0;
    else cout<<s1;
    if(can&&s2!="") cout<<"D"<<s2<<endl;
    return 0;
}
