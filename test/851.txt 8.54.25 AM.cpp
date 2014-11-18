#include<iostream>
using namespace std;
int main(){
    int N,T,L[101],C[101],F[1001]={0};
    cin>>N>>T;
    for(int i=1;i<=N;i++)
            cin>>L[i]>>C[i];
    for(int i=N;i>=1;i--)
            for(int j=T;j>=C[i];j--)
                    F[j]=max(F[j],F[j-C[i]]+L[i]);
    cout<<F[T]<<endl;
    return 0;
}
    

