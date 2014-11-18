#include<iostream>

using namespace std;

int main()
{
    int month[12],handup=0,save=0;
    for(int i=0;i<12;i++)
        cin>>month[i];
    for(int i=0;i<12;i++)
    {
        save+=300-month[i];
        if(save<0)
        {
            cout<<-(i+1)<<endl;
            return 0;
        }
        while(save>100)
        {
            save-=100;
            handup+=100;
        }
    }
    cout<<save+handup+handup/5<<endl;
    return 0;
}                
