#include <iostream>
#include <math.h>
using namespace std;

int n,k,sum=0;
int a[21];

bool ss (int x)
{
     if (x==2)
     {
        return true;
     }
     if (x<2||x%2==0)
     {
        return false;
     }
     for (int i=2;i<=sqrt (x);i++)
     {
         if (x%i==0)
         {
            return false;
         }
     }
     return true;
}

void work (int x,int i,int s)
{
     if (x>k)
     {
        if (ss (s))
        {
           sum++;
        }
     }
     else
     {
         for (int j=i+1;j<=n;j++)
         {
             work (x+1,j,s+a[j]);
         }
     }
}

int main()
{
    int i;
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    work (1,0,0);
    cout<<sum<<endl;
    return 0;
}

