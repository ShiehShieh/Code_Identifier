#include<iostream>
using namespace std;
int main()
{
    int ys[13],g=1,i,sx,now=0,yh=0;
    for(i=1;i<=12;i++) cin>>ys[i];
    for(i=1;i<=12;i++)
    {
                      now=now+300-ys[i];
                      if(now<0) 
                      {
                                g=0;
                                break;
                      }
                      sx=now%100;
                      yh=yh+now-sx;
                      now=sx;
    }
    if(g==0) cout<<-i;
    else cout<<now+yh*1.2;
    return 0;
}
