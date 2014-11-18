#include<iostream>
using namespace std;
struct num {
    char n[1000];
    int p;
    num() {for(int i=0;i<1000;n[i++]=0); p=0;}

    void get() {
        char s[501];
        int i,j;
        cin>>s;
        for(i=0;s[i];i++);
        for(j=0;--i>=0;) if(s[i]=='.') p=j; else n[j++]=s[i]<='9'?s[i]-'0':s[i]-'A'+10;
    }

    void mul(const num&b,int r) {
        num c;
        int i,j,m;
        for(i=0;i<500;i++) {
            for(j=m=0;j<500;j++) {
                m+=(int)n[j]*b.n[i];
                c.n[i+j]+=m%r;
                m/=r;
                if(c.n[i+j]>=r) c.n[i+j]-=r,m++;
            }
            if(m) c.n[i+j]=m;
        }
        for(i=0;i<1000;n[i++]=c.n[i]);
        p+=b.p;
    }

    void out() const {
        int i,j;
        for(i=999;i>=p&&!n[i];i--);
        if(i<p) cout.put('0');
        for(;i>=p;i--) cout.put(n[i]+(n[i]>9?'A'-10:'0'));
        for(j=0;j<p&&!n[j];j++);
        if(j<p) for(cout.put('.');i>=j;i--) cout.put(n[i]+(n[i]>9?'A'-10:'0'));
    }
};

int main() {
    num a,b;
    int r;
    cin>>r;
    a.get();
    b.get();
    a.mul(b,r);
    a.out();
    return 0;
}

