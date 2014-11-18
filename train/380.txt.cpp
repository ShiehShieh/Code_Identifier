#include<iostream>
using namespace std;

char s[45];
int make(long i,long j){
    char ss[45]={0};
    strncpy(ss,s+i,j);
    int k=0;
    for(int xi=0;xi<strlen(ss);++xi)
        k=k*10+ss[xi]-'0';
    return k;
}
int main()
{
    int n,k,f[10][45],a[10][45];
    scanf("%d %d\n",&n,&k);
    scanf("%s",s);
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j){
            a[i][j-i+1]=make(i-1,j-i+1);
            if(i==1) f[1][j]=a[i][j-i+1];
        }
    for(int i=2;i<=k+1;++i)
        for(int j=i;j<=n;++j){
            for(int t=j;t>=i;--t)
                if(f[i][j]<f[i-1][t-1]*a[t][j-t+1])
                    f[i][j]=f[i-1][t-1]*a[t][j-t+1];
        }
    printf("%d\n",f[k+1][n]);
    return 0;
}

