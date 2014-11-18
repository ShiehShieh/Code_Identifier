#include<iostream>
using namespace std;
int main(){
    int time=0,i,j,x,w,n;
    cin>>w>>n;
    int a[200]={0},b[n];
    for(i=0;i<n;i++)
      {cin>>x;
       a[x]++;
      }
    for(i=0,x=0;i<200;i++)
      for(j=0;j<a[i];j++)
        {b[x]=i;
         x++;
        }
    for(i=0,j=x-1;i<=j;)
      {if(b[i]+b[j]<=w)
        {time++;
         i++;
         j--;
        }
       else
        {time++;
         j--;
        }
      }
    cout<<time;
return 0;
}
