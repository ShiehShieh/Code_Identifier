/*Vijos P1059*/
#include <iostream>
using namespace std;

int n,sum,high;
bool f[2][100001];
int main(void)
{
    cin>>n;
    
    for (int i=0;i<=100000;i++)
      {
            f[0][i]=true;
            f[1][i]=false;
      }
    
    high=100000;
    int j;
    
    for (int i=1;i<=n;i++)
      {
            f[1][0]=true;
            sum=0;
            scanf("%d",&j);
            while (j>=0)
              {
                       sum+=j;
                       for (int k=high-j;k>=0;k--)
                         if(f[1][k] == true)
                           f[1][k+j]=true;
                       scanf("%d",&j);
              }
            
            if (sum < high)
              high=sum;
            
            for(int k=1;k<=high;k++)
              {
                    f[0][k]=(f[0][k]&&f[1][k]);
                    f[1][k]=false;
              }
      }
    for (int k=high;k>=0;k--)
      if(f[0][k] == true)
        {
                         printf("%d\n",k);
                         return 0;
        }
}
