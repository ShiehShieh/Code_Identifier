/*
ID:fbcaaa11
PROG:gift1
LANG:C++
*/
#include <iostream>
#include <string>
using namespace std;

char name[10][15];
int money[10];
int total;

int main()
{

     
    char d[15],g[15];
    int t,num,i,j;
    
    cin>>total;
    for(i=0;i<total;++i)
    {
        cin>>name[i];
        money[i]=0;
    }
    while(cin>>d)
    {

        cin>>t>>num;
  
        for(i=0;i<total;++i)
        {
            if(strcmp(d,name[i])==0)
            {
                
                if(num!=0)
                {    money[i]-=t;
                money[i]+=t%num;
                }
                break;
            }
        }
   if(num==0)
            continue;
        t=t/num;
        for(i=0;i<num;++i)
        {
            cin>>g;
            for(j=0;j<total;++j)
            {
                if(strcmp(g,name[j])==0)
                {
                    money[j]+=t;
                    break;
                }
            }
        }
    }
    
    for(i=0;i<total;++i)
    {
        cout<<name[i]<<" "<<money[i]<<endl;
    }
    
    return 0;
}
