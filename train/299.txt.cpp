#include <iostream>
using namespace std;
int main()
{
    int i,j,m,n,js=0;
    cin>>m;
    int b[10000]={}; 
    int a[m]; 
    memset(a,0,sizeof(a)); 
    for(i=0;i<m;i++)
    {
      cin>>a[i];
    }
    for(i=0;i<m;i++)
    {
                    for(j=i;j<m;j++)
                    {
                                     if (a[j]<a[i])swap (a[i],a[j]);
                    }
    }
    for(i=0;i<m;i++)
          b[a[i]]=a[i];
    for(i=0;i<10000;i++)
    {
        if(b[i]!=0)
        js++;               
    } 
    cout<<js<<endl; 
        for(i=0;i<10000;i++)
    {
        if(b[i]!=0)
        cout<<b[i]<<" ";            
    } 
    return 0;
} 
