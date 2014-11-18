#include<iostream>
using namespace std;

int main()
{
    int i,j,n,qm,py,lw,prize,max=0;
    long total=0;
    char a[20],name[20],xb,gb;
    cin>>n;
    for(i=1;i<=n;i++) 
    {
        cin>>a>>qm>>py>>gb>>xb>>lw;
        prize=0;
        if((qm>80)&&(lw>0)) prize+=8000;
        if((qm>85)&&(py>80)) prize+=4000;
        if(qm>90) prize+=2000;
        if((qm>85)&&(xb=='Y')) prize+=1000;
        if((py>80)&&(gb=='Y')) prize+=850;
        total+=prize;
        if(prize>max)
        { 
            max=prize;
            for(j=0;j<20;j++) name[j]=a[j];
        }
    }
    cout<<name<<endl<<max<<endl<<total;
    return 0;
} 
