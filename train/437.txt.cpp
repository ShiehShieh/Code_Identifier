#include <iostream>

using namespace std;

int main()
{
    int x[10001],y[10001],k[10001],tt=0,x1,y1,x2,y2,n,m;
    cin>>n;
    cin>>m;
    while(m!=3)
    {
               if (m==1){
                         tt++;
                         cin>>x[tt]>>y[tt]>>k[tt];
                         }
               else{
                    int sum=0;
                    cin>>x1>>y1>>x2>>y2;
                    for (int i=1;i<=tt;i++)
                        if ((x[i]>=x1)&&(x[i]<=x2)&&(y[i]>=y1)&&(y[i]<=y2)) sum+=k[i];
                    cout<<sum<<endl;
                    }
               cin>>m;
    }
    return 0;
}

