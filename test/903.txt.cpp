#include<iostream>
using namespace std;
int main(){
    string str;
    int i,k,s;
    cin>>str;
    k=1;s=0;
    for(i=0;i<str.size()-1;i++)
      if(str[i]!='-'){s+=(str[i]-'0')*k;
                     k++;
                     }
    s%=11;
    if(s==10)s=390;
    if(s==str[str.size()-1]-'0'||(s==390&&str[str.size()-1]=='X')){cout<<"Right";
                                                              return 0;}
    for(i=0;i<str.size()-1;i++)
      cout<<str[i];
    if(s==390)cout<<'X';
    else cout<<s;
    return 0;
}
    
