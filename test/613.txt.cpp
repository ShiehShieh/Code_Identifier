#include <iostream>
#include <string>
using namespace std;
string s,ss[80],ans[90];
int len,f[80]={1},flag[80],l=0;
bool check(string s1,string s2){
     while (s1[0]=='0') s1.replace(0,1,"");
     while (s2[0]=='0') s2.replace(0,1,"");
     if(s1.size()<s2.size()) return 1;
     else if(s1.size()>s2.size()) return 0;
     else return s1<s2;
}
int main(){
    int i,j,k;
    string s1,s2;
    cin>>s;len=s.size();flag[0]=-1;f[0]=1;ss[0]=s[0];
    //i=1;
    //while (s[i]=='0') {flag[i]=-1;f[i]=1;ss[i]=ss[i-1]+'0';i++;}
    for (i=1;i<len;i++){
        flag[i]=-1;ss[i]=ss[i-1]+s[i];f[i]=1;
        for (j=0;j<i;j++){
            s1=s.substr(j+1,i-j);
            s2=ss[j];
            //cout<<"i="<<i<<" j="<<j<<" s1="<<s1<<" s2="<<s2<<endl;
            if(check(s2,s1)&&f[i]<=f[j]+1) {f[i]=f[j]+1;ss[i]=s1;flag[i]=j;}
        }
    }
    //for (i=0;i<len;i++) cout<<"i="<<i<<" f="<<f[i]<<" ss="<<ss[i]<<" flag="<<flag[i]<<endl;
    i=len-1;
    while (i!=-1) {ans[l++]=ss[i];i=flag[i];}
    for (i=l-1;i>0;i--) cout<<ans[i]<<',';
    cout<<ans[0];
    //while(1);
    return 0;
}

