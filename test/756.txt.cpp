#include<iostream>
using namespace std;
int main()
{
    int i,j,n,m,y;
    cin>>j;
    for (i=1;i<=j;i++)
    {
        cin>>y>>n>>m;
        if(n==9&&m==30)cout<<"YES";
        else if(n==11&&m==30)cout<<"YES";
        else if(!((n+m)%2))cout<<"YES";
        else cout<<"NO";
    }
    return(0);
}

