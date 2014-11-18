#include<iostream>
using namespace std;

int main(void){
    int N,p[15010][2],bucket[15010];
    int i,j,k,t;
    
    cin>>N;
    for(i=0;i<N;i++)
        cin>>p[i][0]>>p[i][1];
        
    memset(bucket,0,sizeof(bucket) );
    for(i=0;i<N;i++){
        t = 0;
        for(j=0;j<N;j++)
            if(j!=i&&p[i][0]>=p[j][0]&&p[i][1]>=p[j][1])
               t++;
               
        bucket[t]++;
    }
    
    for(i=0;i<N;i++)
        cout<<bucket[i]<<endl;
        
    return 0;
}

