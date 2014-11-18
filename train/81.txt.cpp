#include<iostream>
#include<cstring>
using namespace std;

int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}

int main()
{
    int t,m;
    scanf("%d %d",&t,&m);
    int *c=new int[t+1];//开一个数组,在c语言中可以用malloc函数代替
    for(int k=0;k<=t;k++)c[k]=0;
   
    class medic//这里在c语言中可以用结构体代替:把"class"改成"struct",去掉"public:"
    {
          public:
          int value;
          int time;
    }*me;     
   
    me=new medic[m];
    for(int k=0;k<m;k++)
    {
            scanf("%d %d",&me[k].time,&me[k].value);
    }
    for(int j=0;j<m;j++)//枚举药的种类
    {
            for(int k=t;k>=me[j].time;k--)/*计算,注意要k>=me[j].time才能保证k-me[j].time>0 */
            {  
                 c[k]=max(c[k],c[k-me[j].time]+me[j].value);//套前面那个公式
            }
    }
    int max=0;
    for(int k=0;k<=t;k++)/*这里不用这么写,直接输出c[t]就可以了,我写的时候受hyf牛的影响写复杂了 */
    {if(max<=c[k])max=c[k];
    }
    cout<<max;
    getchar();getchar();
    return 0;
}   
