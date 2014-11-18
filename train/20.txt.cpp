#include<cstdio>
#include<cmath>
using namespace std;
long a[10000],num=0;
bool check(long s){
    for(long i=1;i<=num;++i)
        if(a[i]==s) return false;
    return true;
}
long make(long s){
    long len,sum=1;
    len=(long)sqrt(s);
    for(long i=2;i<=len;++i)
        if(s%i==0) sum+=i+s/i;
    if(len*len==s) sum-len;
    return sum;
}
int main()
{
    long n,m;
    scanf("%d %d",&n,&m);
    for(long i=n;i<=m;++i) if(check(i)){
        long k,p;
        k=make(i);
        if(k>i&&k-i<=100000){
            p=make(k);
            if(p==i&&k!=p){
                num++; a[num]=k;
            }
        }
    }
    printf("%d\n",num);
    return 0;
}

