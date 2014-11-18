#include <iostream>
using namespace std;

string a (string s)
{
       string s1,s2;
       s1=s.substr(0,s.size()/2);
       s2=s.substr(s.size()/2,s.size()/2);
       if (s.size()<1) return ""; 
       else if (s.find("10")==string::npos&&s.find("01")==string::npos)
       {
          if (s.at(0)=='0') return a(s1)+a(s2)+"B";
          else return a(s1)+a(s2)+"I";
       }
       else
       {
           return  a(s1)+a(s2)+"F";
       }
}

int main()
{
    string str;
    int n; 
    cin>>n>>str;
    cout<<a(str);
    return 0;
} 

