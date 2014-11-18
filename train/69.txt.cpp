#include<iostream>
#include<string>
using namespace std;
int a[99],b[99],p=0;char ch;
string s;
void set1( ){
    getline(cin,s);
    a[0]=b[0]=0;
    while (s[p]!='='){
        int k=1,r=0;
        if (s[p]=='-'){
            k=-1;p++;
        }else if (s[p]=='+') p++;
        while (s[p]>='0' && s[p]<='9'){
            r=r*10+s[p]-'0';
            p++;
        }
        if (s[p]>='a' && s[p]<='z'){
            if (r==0) r=k;
            a[++a[0]]=r*k;
            ch=s[p];
            p++;
        }
        else b[++b[0]]=-k*r;
        if (s[p]=='=') break;
    }
}
void set2(){
    p++;
    while (p<s.size()){
        int k=1,r=0;
        if (s[p]=='-'){
            k=-1;p++;
        }else if (s[p]=='+') p++;
        while(s[p]>='0' && s[p]<='9'){
            r=r*10+s[p]-'0';
            p++;
        }
        if (s[p]>='a' && s[p]<='z'){
            if (r==0) r=k;
            a[++a[0]]=-k*r;
            ch=s[p];
            p++;
        }else b[++b[0]]=k*r;
    }
    printf("%c=",ch);
}
void work(){
    double s=0,ss=0;
    for (int i=1;i<=a[0];i++) s+=a[i];
    for (int i=1;i<=b[0];i++) ss+=b[i];
    if (ss==0 || s==0) printf("0.000\n");
    else {
        double ans=ss/s;
        printf("%0.3lf\n",ans);
    }
}
int main()
{
    set1();
    set2();
    work();
    return 0;
}
