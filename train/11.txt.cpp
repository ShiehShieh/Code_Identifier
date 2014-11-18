#include<iostream>
#include<cmath>
using namespace std;
const int range=200000;
int k,i,j,l[range],data[20][range],n,query,a,b;
int main()
{
    //rmq比较特殊，data数组中小的一维应该放在前面,这是mmd大牛教导的
    //freopen("a.in","r",stdin);freopen("a.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;++i)
        scanf("%d",&l[i]);
    int po=1;j=0;
    memset(data,0,sizeof(data));
    for (i=1;i<=n;++i)
        data[0][i]=l[i];
    while (po*2<n){
        po*=2;
        j++;
        int te=n-po+1;
        for (i=1;i<=te;++i)
            data[j][i]=data[j-1][i]>data[j-1][i+po/2]?data[j-1][i]:data[j-1][i+po/2];
    }//又在细节上犯了错误,之前多减了一
    scanf("%d",&query);
    for (i=1;i<=query;++i){
        scanf("%d%d",&a,&b);
        if (a>b) {printf("Please check the input data\n");continue;}
        k=(int)(log(b-a+1)/log(2));
        printf("%d\n",data[k][a]>data[k][b-(int)pow(2,(double)k)+1]?data[k][a]:data[k][b-(int)pow(2,(double)k)+1]);
    }
}

