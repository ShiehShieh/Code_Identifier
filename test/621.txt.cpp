#include <iostream>
using namespace std;
class T
{
    private:
        int t,m,ti[2000],c[2000],f[2000];
    public:
        void input()
        {
            cin>>t>>m;
            for(int i=1;i<=m;i++)
                cin>>ti[i]>>c[i];
        }
        void dp()
        {
            for(int i=1;i<=m;i++){
                for(int j=t;j>=ti[i];j--){
                    if(f[j]<f[j-ti[i]]+c[i])
                        f[j]=f[j-ti[i]]+c[i];
                }
            }
        }
        void output()
        {
            cout<<f[t]<<endl;
        }
};
T vj;
int main()
{
    vj.input();
    vj.dp();
    vj.output();
    return 0;
}
