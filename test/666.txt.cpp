#include<iostream>
#include<string>
using namespace std;
string tg(string s)
{
string s1,s2;
 s1=s.substr(0,s.length()/2);
 s2=s.substr(s.length()/2,s.length()/2);
 if(s.length()<1)return"";
if(s.find("10")==string::npos&&s.find("01")==string::npos)
{if(s.at(0)=='0')return tg(s1)+tg(s2)+"B";
  else return tg(s1)+tg(s2)+"I";
}
else{
    return tg(s1)+tg(s2)+"F";
     }
     }
main(){
       int n;
       string str;
       cin>>n>>str;
       cout<<tg(str);
       return 0;
       }     
       

