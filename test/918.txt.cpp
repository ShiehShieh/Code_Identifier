#include <iostream>
using namespace std;
int main()
{
        int n,shu,ying;
        cin>>n;
        int yu[n+1],xh[n+1],he[n+1];
        for(int i=1;i<=n;i++)
        {
                cin>>yu[i]>>shu>>ying;
                he[i]=yu[i]+shu+ying;
                xh[i]=i;
        }
        for(int i=1;i<n;i++)
        {
                for(int j=1;j<=n-i;j++)
                {
                        if(he[j]<he[j+1]||he[j]==he[j+1]&&yu[j]<yu[j+1])
                        {
                                swap(he[j],he[j+1]);
                                swap(yu[j],yu[j+1]);
                                swap(xh[j],xh[j+1]);
                        }
                }
        }
        for(int i=1;i<=5;i++)
        {
                cout<<xh[i]<<' '<<he[i]<<endl;
        }
        return 0;
}

