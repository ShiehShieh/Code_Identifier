#include <iostream>
using namespace std;
class p1123
{
    private:
        int n,a[200];
    public:
        int c;
        int sum;
        int abs(int);
        void init()
        {
            sum=0;
            cin>>n;
            for(int i=1;i<=n;i++){
                cin>>a[i];
                sum+=a[i];
            }
            sum/=n;
        }
        void work()
        {
            c=0;
            for(int i=1;i<=n;i++){
                a[i]-=sum;
                if(a[i]){
                    a[i+1]+=a[i];
                    a[i]=0;
                    c++;
                }
            }
            cout<<c<<endl;
        }
}wori;
int main()
{
    wori.init();
    wori.work();
    return 0;
}
