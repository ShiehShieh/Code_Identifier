#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
int k,len;
double xt=1.0;
char n[40];
bool f[10][10];
int cou[10]={0};
int main(){
    cin>>n>>k;len=strlen(n);//printf("s=%s\n",n);
    int i,j,k,x,y;
    for (i=1;i<=k;i++) {cin>>x>>y;f[x][y]=1;}
    for (i=0;i<=9;i++) f[i][i]=1;
    for (k=0;k<=9;k++)
        for (i=0;i<=9;i++)
            for (j=0;j<=9;j++)
                if(f[i][j]) continue;
                else f[i][j]=f[i][k]&&f[k][j];
    for (i=0;i<=9;i++) for (j=0;j<=9;j++) if(f[i][j]) cou[i]++;
    //for (i=1;i<=9;i++) printf("%d ",cou[i]);
    //printf("\n");
    for (i=0;i<len;i++) {/*printf("%d\n",n[i]);*/xt*=cou[n[i]-48];}
    cout<<fixed;
    cout<<setprecision(0)<<xt;
    //while(1);
    return 0;
}

