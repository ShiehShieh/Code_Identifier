#include<iostream>
using namespace std;
struct jgt
{
char mz[20];
int qm;
int bj;
char gb;
char xb;
int lw;
int qian;
};

int main()
{
    int n,i;
    cin>>n;
    jgt *ziliao=new jgt[n];
    for(i=0;i<n;i++)
    {
    cin>>ziliao[i].mz>>ziliao[i].qm>>ziliao[i].bj>>ziliao[i].gb>>ziliao[i].xb>>ziliao[i].lw;
    if(ziliao[i].qm>80&&ziliao[i].lw>=1)
    ziliao[i].qian+=8000;
    if(ziliao[i].qm>85&&ziliao[i].bj>80)
    ziliao[i].qian+=4000;
    if(ziliao[i].qm>90)
    ziliao[i].qian+=2000;
    if(ziliao[i].qm>85&&ziliao[i].xb=='Y')
    ziliao[i].qian+=1000;
    if(ziliao[i].bj>80&&ziliao[i].gb=='Y')
    ziliao[i].qian+=850;
    }
    int s=0,k;
    for(int j=0;j<=n-1;j++)
    {
    if(ziliao[j].qian>s)
    {
    s=ziliao[j].qian;
    k=j;
    }
    }
    int ss=0;
    for(i=0;i<n;i++)
    {
    ss+=ziliao[i].qian;
    }
    cout<<ziliao[k].mz<<endl;
    cout<<ziliao[k].qian<<endl;
    cout<<ss<<endl;  
    return 0;
}

