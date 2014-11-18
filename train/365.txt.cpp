#include<iostream>
#include<cmath>
using namespace std;

struct arr{
    long x,y,c;
}a[400];
int cmp(const void* no1,const void* no2){
    arr *nox=(arr*)no1,*noy=(arr*)no2;
    return nox->c - noy->c;
}
int main()
{
    long n,m,l=0,t;
    scanf("%d %d %d",&n,&m,&t);
    for(long i=1;i<=n;++i)
        for(long j=1;j<=m;++j){
            long c;
            scanf("%d",&c);
            if(c){
                a[++l].x=i;
                a[l].y=j;
                a[l].c=c;
            }
        }
    qsort(a+1,l,sizeof(arr),cmp);
    long x,y,ans=0;
    x=a[l].x; y=a[l].y;
    if(t>=2*x+1){
        ans+=a[l].c;
        t-=x+1;
    }
    else t=0;
    for(long i=l-1;i>=1;--i){
        long xi,yi;
        xi=a[i].x; yi=a[i].y;
        if(abs(xi-x)+abs(yi-y)+xi+1<=t){
            ans+=a[i].c;
            t-=abs(xi-x)+abs(yi-y)+1;
            x=xi; y=yi;
        }
        else break;
    }
    printf("%d\n",ans);
    return 0;
}
