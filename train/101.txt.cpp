#include<cstdio>
using namespace std;

long l,a[102],s,t,n;
long f[10000000],d[10000000];
void init(){
    scanf("%ld %ld %ld %ld",&l,&s,&t,&n);
    for(long i=1;i<=n;++i) scanf("%ld",&a[i]);
}
void solve()
{
    long num;
    if(s==t){
        num=0;
        for(long i=1;i<=n;i++)
            if(a[i]%s==0) num++;
        printf("%d\n",num);
        return;
    }
    long tmp;
    for(long i=1;i<n;++i)
        for(long j=i+1;j<=n;++j)
            if(a[i]>a[j]){
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
    a[n+1]=l;
    for(long i=1;i<=n;++i)
        if(a[i+1]-a[i]>90)
            a[i+1]=a[i]+(a[i+1]-a[i])%90;
    l=a[n+1];
    for(long i=1;i<=n;++i) d[a[i]]=1;
    for(long i=1;i<=l+t;++i) f[i]=0xFFFFFFF;
    for(long i=s;i<=l+t;++i)
        for(long j=s;j<=t;++j)
            if(i>=j&&f[i]>f[i-j]+d[i])
                f[i]=f[i-j]+d[i];
    num=0xFFFFFFF;
    for(long i=l;i<=l+t;++i)
        if(num>f[i]) num=f[i];
    printf("%d\n",num);
}
int main()
{
    init();
    solve();
    return 0;
}

