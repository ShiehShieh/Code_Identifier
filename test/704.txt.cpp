#include <iostream>
using namespace std;

int E[11001],P[11001],pn=0;

int f(int a)
{
    int x[21],y[21],n=0,i=1,j,b=a;
    while (P[i]*P[i]<=b)
    {
        if (b%P[i]==0)
        {
            n++;
            x[n]=P[i];
            y[n]=0;
        }   
        
        while (b%P[i]==0)
        {
            b=b/P[i];
            y[n]++;
        }
        i++;
    }
    if (b>P[i])
    {
        n++;
        x[n]=b;y[n]=1;
    }
    int p,q,s=1;
    for (i=1;i<=n;i++)
    {
        p=1;q=0;
        for (j=0;j<=y[i];j++)
        {
            q=q+p;
            p=p*x[i];
        }
        s=s*q;
    }
    s=s-a;
    return s;
}
             
int main()
{
    
    int i,j;
    memset(E,1,sizeof(E));
    E[1]=0;
    for (i=2;i*i<=11000;i++)
        if (E[i])
            for (j=2*i;j<=11000;j+=i) E[j]=0;
    for (i=1;i<=11000;i++)
        if (E[i])
        {
            pn++;
            P[pn]=i;
        }
    int A,B,s=0;
    cin>>A>>B;
    for (i=A;i<=B;i++)
    {
        if (f(i)>i&&f(f(i))==i)
        {
            s++;
        }
    }
    cout<<s<<endl;
    return 0;
}
