#include<iostream>
using namespace std;
long long maxex(long long x,long long y)
{if(x>y)return x;
return y;
}
int main()
{long long n,r,g,b,t,i,j,k,d[1024],p[1024],amax;
     cin>>n>>r>>g>>b>>t;
    p[0]=0;
    i=0;
    for(j=1;j<=n;j++){
                      p[j]=p[j-1]+(j-1)*g*t;
                      if(p[j]+(r+g*j)*(i*b+t)*(n-i-j)>amax&&i+j<=n)
                      amax=p[j]+(r+g*j)*(i*b+t)*(n-i-j);
                      }
    amax=0;
    for(i=1;i<=n;i++){
    for(j=0;j<=n-i;j++){
                        if(j==0)d[j]=0;
                        else
                        d[j]=maxex(p[j]+j*g*(t+(i-1)*b),d[j-1]+(j-1)*(t+b*i)*g);
                         if(d[j]+(r+g*j)*(i*b+t)*(n-i-j)>amax&&i+j<=n)
                         amax=d[j]+(r+g*j)*(i*b+t)*(n-i-j);
                       }
                       for(k=0;k<=n;k++)p[k]=d[k];
                     }
    cout<<amax<<endl;
    return 0;
}

