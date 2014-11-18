/*
ID: ashuai11
PROG: gift1
LANG: C++
*/



#include <iostream>
using namespace std;

int N;
char Name[10][15];


int find(char str[]);

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>Name[i];
    }

    char str[15];
    int k1,k2,i = 0;
    int n,start,give,income[N],outcome[N];
    memset(income,0,sizeof(income));
    memset(outcome,0,sizeof(outcome));
    
    while(i<N)
    {
        cin>>str>>start>>n;
        k1 = find(str);
        if(n!=0)
            give = start / n;
        else 
            give = 0;
        outcome[k1] += give * n;
        for(int j = 0;j<n;j++)
        {
            cin>>str;
            k2 = find(str);
            income[k2] += give;
        }
        i++;
    }
    
    for(i = 0;i<N;i++)
        cout<<Name[i]<<" "<<income[i]-outcome[i]<<endl;

    return 0;
}

int find(char str[15])
{
    int i;
    for(i = 0;i<N;i++)
        if(!strcmp(str,Name[i]))
            return i;

}

