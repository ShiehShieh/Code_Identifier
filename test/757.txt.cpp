#include<iostream>
#include<string>
using namespace std;
int main()
{   string str1, str2;
    getline(cin, str1, '\n');
    getline(cin, str2, '\n');
    str2[str2.size()-1] = ' ';  
    string temp(" is "); 
    int r=str2.find(temp)+3; 
    temp=str2.substr(0, r);
    if(temp[0]>='A'&&temp[0]<='Z') 
      temp[0]+='a'-'A';
    str2 = str2.substr(r,str2.size()-r); 
    str1+=str2+temp+'!';    
     cout<<str1<<endl;
    return 0;
}

