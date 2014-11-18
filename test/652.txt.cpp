#include <iostream>

using namespace std;
int n,p,t;
bool zhi(int k)
{
    for (p=2;p*p<=k;p++)
    if (k%p==0)
    return false;
    return true;
}
void force(int m,int w)
{
    int q;
    if (m>n) cout<<w<<endl;
    if ((m<=n)&&(m>1))
    for (q=1;q<=9;q=q+2)
    {
        t=w*10+q;
        if (zhi(t))
        force(m+1,t);
    }
}
int main()
{
    cin>>n;
    force(2,2);
    force(2,3);
    force(2,5);
    force(2,7);
    return 0;
}

