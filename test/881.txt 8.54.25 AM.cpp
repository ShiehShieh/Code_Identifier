#include<iostream>
using namespace std;
int T[]={0,0,1,1,0,0,0,1,1,0};
char a[10000],b[10000];
int main()
{
    
    for(int i=1;i<=10;i++)
   { int aa,bb;cin>>a>>b;
     aa=(a[strlen(a)-1]-48);
     bb=(b[strlen(b)-1]-48);
    if(!T[aa]||!T[bb])cout<<"Matrix67"<<endl;
    else cout<<"Shadow"<<endl;
}

}

