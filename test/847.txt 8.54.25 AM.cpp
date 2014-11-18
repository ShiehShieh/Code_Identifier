#include <iostream>
using namespace std;
long long X0,Y0;

long long extendGCD(long long a,long long b)
{
    if (b==0)
    {
        X0=1;
        Y0=0;
        return a;
    }
    long long d=extendGCD(b,a%b);//a,b 的最大公约数;
    long long t=X0;
    X0=Y0;
    Y0=t-(a/b)*X0;//求一组方程的解；

    return d;
}

int main()
{
    long long x,y,m,n,L;
    while (cin>>x>>y>>m>>n>>L)
    {
        long long A=m-n;    
        long long B=L;
        long long C=y-x;

        if (A<0)
        {
            A=-A;
            C=-C;
        }

        long long d=extendGCD(A,B);
        if (m==n||C%d!=0)
        {
            printf("Impossible\n");
        }
        else
        {
            B/=d;
            C/=d;
            long long t=C*X0;
            cout<<(t%B+B)%B<<endl;
        }
    }
    return 0;
}
